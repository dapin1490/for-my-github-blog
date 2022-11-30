import requests
import json
import re
import numpy as np
from bs4 import BeautifulSoup
import requests, lxml, os, json
#import collections
import pandas as pd
from time import sleep
# change this for a different search term
search_term = "%28virtual OR Metaverse%29 AND service"
# change this for different page no
page_no = 1
page_num = 50
paper_type = '"Article"'
#118222 Proceedings
#118230 Journals
#headers = {
#    "Accept": "application/json, text/plain, */*",
#    "Origin": "https://link.springer.com",
#    "Content-Type": "application/json",
#}
headers = {
    'User-agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"}


url_base="https://link.springer.com/search/page/"
url_addr=url_base+str(page_no)+"?"+"query="+search_term.replace(" ","+")
print(url_addr)
r = requests.get(
        url_addr,
        headers=headers
    )
print(r.status_code)
soup = BeautifulSoup(r.content,'html.parser')
#print(soup.find_all())

results = soup.find('h1', {'id':"number-of-search-results-and-search-terms"})
results_1 = int(results.select_one("strong").text.replace(",",""))
cnt = 1
t_num = results_1
print(t_num)
np_arr = np.empty((t_num+500,7),dtype="U500")
#df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])

cnt = 0
for year_c in range(1976,2024):
    page_no=1
   #https://link.springer.com/search?query=%28virtual+OR+VR+OR+augmented+OR+AR+OR+Metaverse+OR+CPS%29+AND+robot+AND+service+AND+scenario&date-facet-mode=between&facet-start-year=1976&facet-end-year=1976 
    url_addr=url_base+str(page_no)+"?"+"query="+search_term.replace(" ","+")+"&date-facet-mode=between&facet-start-year="+str(year_c)+"&facet-end-year="+str(year_c)
    #print(url_addr)
    r_res = 0
    while(r_res != 200):
        try:
            r = requests.get(
                    url_addr,
                    headers=headers
                )
            r_res=r.status_code
        #    print(r_res)
        except:
            sleep(3)
            r_res=0

    #print(r.status_code)
    soup = BeautifulSoup(r.content,'html.parser')
    #print(soup.find_all())

    results = soup.find('h1', {'id':"number-of-search-results-and-search-terms"})
    results_1 = int(results.select_one("strong").text.replace(",",""))
    page_len = int(np.ceil(results_1/20))+1
    for page_no in range(1,page_len):
        url_base="https://link.springer.com/search/page/"
        url_addr=url_base+str(page_no)+"?"+"query="+search_term.replace(" ","+")+"&date-facet-mode=between&facet-start-year="+str(year_c)+"&facet-end-year="+str(year_c)
        r_res = 0
        print(url_addr)
        while(r_res != 200):
            try:
                r = requests.get(
                        url_addr,
                        headers=headers
                    )
                r_res=r.status_code
        #        print(r_res)
            except:
                sleep(3)
                r_res=0
        #print(r.status_code)
        soup = BeautifulSoup(r.content,'html.parser')
        #print(soup.find_all()) 

        page_1 = soup.find_all("ol", class_="content-item-list")
        page_list = page_1[0].find_all("li")
        #print(page_list)
        for result in page_list:
            type_p = result.find_all("p", class_="content-type")
            #print(type_p[0].text)
            title = result.select_one("a", class_="title")
            #if title is not None:
            #    print(title.text)
            
            if title is not None:
                link = title.get('href')
            else:
                link = None
            #print("https://link.springer.com"+link)
            abstract = result.find_all("p", class_="snippet")
            #if len(abstract) > 0:
            #    print(abstract[0].text)
            
            pub1 = result.find_all("p", class_="subtitle")
            if(len(pub1)==0):
                pub1 = result.find_all("a", class_="publication-title")
                if(len(pub1)>0):
                    pub = pub1[0].get("title")
                else:
                    pub=""
            else: 
                pub=pub1[0].text.replace("\n"," ").replace("\r"," ")

            #print(pub)
            #print(pub[0].text)
            meta_1 = result.find_all("p", class_="meta")

            if len(meta_1) > 0:
                authors = meta_1[0].select_one("span",class_="authors")
            #    if authors is not None:
            #        print(authors.text)

                year = meta_1[0].find_all("span", class_="enumeration")
            #    if year is not None:
            #        print(year[0].text)
                year = re.findall("\d+",year[0].text.replace("(","").replace(")","").replace("\n"," ").replace("\r"," "))
                if len(year) < 4:
                    year = [year_c]

                meta_flag = 0
                
            else:
                authors = None
                year = [year_c]
                meta_flag = 1
            #print("---------------------")
            #print("No.", cnt)
            if title is not None:
            #    print("1)", title.text.replace("\n"," ").replace("\r"," "))
                np_arr[cnt][1] = title.text.replace("\n"," ").replace("\r"," ")
            if authors is not None:
            #    print("2)", authors.text.replace("\n"," ").replace("\r"," "))
                np_arr[cnt][0] = authors.text.replace("\n"," ").replace("\r"," ")
            
            if pub is not None:
            #    print("3)", pub)
                np_arr[cnt][3] = pub
            if len(year) > 0:
                if meta_flag == 1:
                    np_arr[cnt][2] = year[0]
                else:
            #        print("4)", year[0])
                    np_arr[cnt][2] = year[0]
                
                meta_flag = 0

            if len(type_p) > 0:
            #    print("5)", type_p[0].text.replace("\n"," ").replace("\r"," "))
                np_arr[cnt][4] = type_p[0].text.replace("\n"," ").replace("\r"," ")

            if len(abstract) > 0:
            #    print("6)", abstract[0].text.replace("\n"," ").replace("\r"," "))
                np_arr[cnt][5] = abstract[0].text.replace("\n"," ").replace("\r"," ")

            if link is not None:
            #    print("7)", "https://link.springer.com"+link)
                np_arr[cnt][6] ="https://link.springer.com"+link
            cnt += 1


df = pd.DataFrame(np_arr[:cnt,:], columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
df = df.drop_duplicates()
df.to_csv("springer_data.csv")
df.to_excel("springer_data.xlsx")
