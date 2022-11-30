import requests
import json
import re
import numpy as np
from bs4 import BeautifulSoup
import requests, lxml, os, json
from os.path import exists
#import collections
import pandas as pd

page_no = 1
page_num = 100
paper_type = "FLA"


html_name = "test_page-0-1-2022.html"

with open(html_name) as fp:
    soup = BeautifulSoup(fp, 'html.parser')

t_num = 12101 
 

#r = requests.get(
#        url_addr,
#	headers=headers
#    )
np_arr = np.empty((t_num,7),dtype="U500")
#df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
cnt = 0
for year_c in range(1999,2024):
    for page_no in range(0,21):
        html_name = "test_page-0-"+str(page_no)+"-"+str(year_c)+".html"
        print(year_c, page_no,cnt)
        if exists(html_name):
            with open(html_name) as fp:
                soup = BeautifulSoup(fp, 'html.parser')

            #print(soup.find_all())

            results_list = soup.find_all("li",class_ = "ResultItem col-xs-24 push-m")
            for results in results_list:
                type_p = results.find_all("span", class_="article-type u-clr-grey8")
                #if len(type_p) > 0:
                #    print(type_p[0].text)
                title = results.find_all("span",class_="anchor-text")
                pub = results.find_all("span",class_="srctitle-date-fields")
                link_1 = results.find_all("a", class_="anchor download-link anchor-default")
                if len(link_1) > 0:
                    link = link_1[0].get('href')

                #print(pub[0].text)
                year = re.findall("\d+",pub[0].text)
                #print(year)
                if len(year) > 1 and len(year[0]) < 4:
                    year = year[1]
                else:
                    year = year[0][len(year[0])-4:len(year[0])]
                author = results.select_one("ol", class_="Authors hor")
                abstract = "http://doi.org/"+results.get("data-doi")
                #if len(type_p) > 0:
                #    print(type_p[0].text)
                #print(title[0].text)	
                #print(pub[0].text)
                #print(year)	
                #print(author.text)
                #print(abstract)
                #print(link)
                #print("------------------------")

                if len(title) > 0:
                    print("1)", title[0].text)
                    np_arr[cnt][1] = title[0].text
                if author is not None:
                    print("2)", author.text)
                    np_arr[cnt][0] = author.text
                if len(pub) > 0:
                    print("3)", pub[0].text)
                    np_arr[cnt][3] = pub[0].text
                if year is not None:
                    print("4)", year)
                    np_arr[cnt][2] = year
                if len(type_p) > 0:
                    print("5)", type_p[0].text)
                    np_arr[cnt][4] = type_p[0].text
                if abstract is not None:
                    print("6)", abstract)
                    np_arr[cnt][5] = abstract
                if link is not None:
                    print("7)", link)
                    np_arr[cnt][6] = link
                
                cnt = cnt + 1

df = pd.DataFrame(np_arr[:cnt,:], columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
df = df.drop_duplicates()
df.to_csv("sciencedirect_data.csv")
df.to_excel("sciencedirect_data.xlsx")
