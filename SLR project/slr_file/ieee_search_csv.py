import requests
import json
import numpy as np
import pandas as pd
# change this for a different search term
search_term = "(virtual OR Metaverse) AND service"
# change this for different page no
page_no = 1

headers = {
    "Accept": "application/json, text/plain, */*",
    "Origin": "https://ieeexplore.ieee.org",
    "Content-Type": "application/json",
}

payload = {
    "newsearch": True,
    "queryText": search_term,
    "highlight": True,
    "returnFacets": ["ALL"],
    "returnType": "SEARCH",
    "rowsPerPage":100,
    "pageNumber": page_no,
    "resultsFilter":["content_type", "Journals"]
}
r = requests.post(
        "https://ieeexplore.ieee.org/rest/search",
        json=payload,
        headers=headers
    )
page_data = r.json()
print(page_data.keys())
print(page_data["totalRecords"])
#print(page_data["startRecord"])

iter_num = int(np.ceil(float(page_data["totalRecords"])/100))
cnt = 0
t_num =int(page_data["totalRecords"]) 
np_arr = np.empty((t_num,7),dtype="U500")
#df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
for page_no in range(1,iter_num+1):
    payload = {
            "newsearch": True,
            "queryText": search_term,
            "highlight": True,
            "returnFacets": ["ALL"],
            "returnType": "SEARCH",
            "rowsPerPage":100,
            "pageNumber": page_no,
            "resultsFilter":["content_type", "Journals"]
            }
    r = requests.post(
            "https://ieeexplore.ieee.org/rest/search",
            json=payload,
            headers=headers
            )  
    page_data = r.json()
    for record in page_data["records"]:
        rlist = record["contentType"].split(" ")
        authors=""
        for i in range(0,len(record["authors"])):
            if (i==len(record["authors"])-1):
                print(record["authors"][i]['preferredName'])
                authors=authors+record["authors"][i]['preferredName']
            else:
                print(record["authors"][i]['preferredName']+", ", end=" ")
                authors=authors+record["authors"][i]['preferredName']+", "
        print(cnt)
        np_arr[cnt][0] = authors
        print(record["articleTitle"])
        np_arr[cnt][1] = record["articleTitle"]
        print(record["publicationYear"])
        np_arr[cnt][2] = record["publicationYear"]
        print(record["publicationTitle"])
        np_arr[cnt][3] = record["publicationTitle"]
        print(rlist[1])
        np_arr[cnt][4] = rlist[1]
        print(record["abstract"])
        np_arr[cnt][5] = record["abstract"]
        print('https://ieeexplore.ieee.org'+record["documentLink"], end="\n----\n")
        np_arr[cnt][6] = 'https://ieeexplore.ieee.org'+record["documentLink"]
        #np_arr[cnt] = (authors, record["articleTitle"],record["publicationYear"],record["publicationTitle"],rlist[1], record["abstract"],  'https://ieeexplore.ieee.org'+record["documentLink"])
        cnt = cnt + 1
print(np_arr)

df = pd.DataFrame(np_arr, columns=["Authors", "Title", "Year","Publication","Type","Abstract","Link"])
df.to_csv("ieee_data.csv")
#dict_keys(['authors', 'patentCitationCount', 'accessType', 'rightsLink', 'pdfSize', 'startPage', 'endPage', 'publicationDate', 'rightslinkFlag', 'showHtml', 'downloadCount', 'htmlLink', 'citationsLink', 'documentLink', 'articleNumber', 'doi', 'citationCount', 'isNumber', 'showAlgorithm', 'showDataset', 'showVideo', 'ephemera', 'vj', 'articleTitle', 'graphicalAbstract', 'publicationLink', 'publicationYear', 'publicationNumber', 'publisher', 'handleProduct', 'showCheckbox', 'redline', 'contentType', 'pdfLink', 'abstract', 'articleContentType', 'highlightedTitle', 'publicationTitle', 'displayPublicationTitle', 'isStandard', 'docIdentifier', 'isJournalAndMagazine', 'displayContentType', 'isEarlyAccess', 'isMagazine', 'isJournal', 'isBook', 'course', 'isBookWithoutChapters', 'isConference'])

