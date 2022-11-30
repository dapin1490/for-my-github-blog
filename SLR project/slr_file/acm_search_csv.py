import requests
import json
import numpy as np
from bs4 import BeautifulSoup
import requests, lxml, os, json
import re
#import collections
import pandas as pd

# change this for a different search term
search_term = "(virtual OR Metaverse) AND service"
# change this for different page no
page_no = 0
page_num = 50
paper_type = "118230"

year_range = range(1976,2023)





headers = {

    "Accept": "application/json, text/plain, */*",
    "Origin": "https://dl.acm.org",
    "Content-Type": "application/json",
}


url_base="https://dl.acm.org/action/doSearch"
url_addr=url_base+"?"+"AllField="+search_term.replace(" ","+")+"&"+\
        "startPage="+str(page_no)+"&"+"pageSize="+str(page_num)

print(url_addr)
r = requests.post(
        url_addr,
        headers=headers
    )
print(r.status_code)
soup = BeautifulSoup(r.content,'html.parser')

page_t_number = soup.find_all("span", class_="hitsLength")
print(page_t_number)
page_len_1 = page_t_number[0].text
page_len = page_len_1
page_len = int(page_len.replace(",",""))
print(page_len)
#input()

cnt = 0

t_num =int(page_len) 
np_arr = np.empty((t_num,7),dtype="U500")
for year_num in year_range:

    #118222 Proceedings
    #118230 Journals
    headers = {
        "Accept": "application/json, text/plain, */*",
        "Origin": "https://dl.acm.org",
        "Content-Type": "application/json",
    }


    url_base="https://dl.acm.org/action/doSearch"
    url_addr=url_base+"?"+"AllField="+search_term.replace(" ","+")+"&"+\
            "startPage="+str(page_no)+"&"+"pageSize="+str(page_num)+"&AfterYear="+str(year_num)+ "&BeforeYear="+str(year_num)

    print(url_addr)
    r = requests.post(
            url_addr,
            headers=headers
        )
    print(r.status_code)
    soup = BeautifulSoup(r.content,'html.parser')

    page_t_number = soup.find_all("span", class_="hitsLength")
    print(page_t_number)
    page_len_1 = page_t_number[0].text
    page_len = page_len_1
    page_len = int(page_len.replace(",",""))
    print(page_len)

    #df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
    for page_no in range(0,int(page_len/page_num)+1):

        url_base="https://dl.acm.org/action/doSearch"
        url_addr=url_base+"?"+"AllField="+search_term.replace(" ","+")+"&"+\
                "startPage="+str(page_no)+"&"+"pageSize="+str(page_num)+"&AfterYear="+str(year_num)+ "&BeforeYear="+str(year_num)

        print(url_addr)
        r = requests.post(
            url_addr,
            headers=headers
            )
        #print(r.status_code)
        soup = BeautifulSoup(r.content,'html.parser')


        rlist = soup.find_all('div', class_ = "issue-item__content-right")
        typelist = soup.find_all('div', class_ = "issue-heading")

        #print(len(rlist))
        cnt1=0
        for result in rlist:
            title = result.select_one("span",class_="hlFld-Title")
            authors = result.select_one("ul",class_="rlist--inline loa truncate-list trunc-done")
            abstract_1= result.find_all("div", class_="issue-item__abstract truncate-text")
            abstract= abstract_1[0].select_one("p")
            name_1 = result.find_all("div",class_="issue-item__detail")
            if not name_1:
                continue
            else:
                name = name_1[0].select_one("span",class_="epub-section__title")
                year1 = name_1[0].find_all("span",class_="dot-separator")
                year2 = year1[0].select_one("span > span")
                year = re.findall("\d+",year2.text)[0]
                type1 = typelist[cnt1]
                link_1 = name_1[0].find_all("a", class_="issue-item__doi dot-separator")
                if not link_1:
                    link=""
                else:
                    link=link_1[0].get('href')
                print(cnt, "-----------")
                if title is not None:
                    print("1)", title.text)
                    np_arr[cnt][1] = title.text
                if authors is not None:
                    print("2)", authors.text)
                    np_arr[cnt][0] = authors.text
                if name is not None:
                    print("3)", name.text)
                    np_arr[cnt][3] = name.text
                if year is not None:
                    print("4)", year)
                    np_arr[cnt][2] = year
                if type1 is not None:
                    print("5)", type1.text)
                    np_arr[cnt][4] = type1.text
                if abstract is not None:
                    print("6)", abstract.text)
                    np_arr[cnt][5] = abstract.text
                if link is not None:
                    print("7)", link)
                    np_arr[cnt][6] = link
                cnt = cnt + 1
                cnt1=cnt1+1
                #title_link = result.select_one('.gs_rt a')['href']
                #publication_info = result.select_one('.gs_a').text
                #snippet = result.select_one('.gs_rs').text
                #cited = result.select_one('.gs_fl').tex

df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
df.to_csv("acm_data.csv")
