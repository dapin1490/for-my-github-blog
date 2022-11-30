from tkinter.messagebox import NO
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.chrome.options import Options
import pandas as pd
from datetime import datetime

# steam web api doc : https://steamapi.xpaw.me/#IStoreService/GetAppList

chrome_driver = ChromeDriverManager().install()
service = Service(chrome_driver)

# reference : https://stackoverflow.com/questions/72758996/selenium-seleniumwire-unknown-error-cannot-determine-loading-status-from-unkn
# also reference : https://stackoverflow.com/questions/46920243/how-to-configure-chromedriver-to-initiate-chrome-browser-in-headless-mode-throug
# CHROMEDRIVER_PATH = r"C:\Users\dpgbu\.wdm\drivers\chromedriver\win32\103.0.5060.53\chromedriver.exe"
options = Options()
# options.headless = True
driver = webdriver.Chrome(service=service)#, options=options)
driver.implicitly_wait(2)

# steamURL = "https://store.steampowered.com/"  # 기본 링크

# steam 크롤링
gameURL = "https://www.sciencedirect.com/search?qs=virtual%20environment"  # 게임 아이디로 상점 페이지 링크 생성

driver.get(gameURL)
st = "#srp-results-list > ol > li:nth-child(1) > div > div.result-item-content"
res = driver.find_element(By.CSS_SELECTOR, st).text.strip()
print(res)
# #srp-results-list > ol > li:nth-child(1) > div > div.result-item-content
