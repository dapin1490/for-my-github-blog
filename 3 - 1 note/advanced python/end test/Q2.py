'''
성신여대는 1936년 4월 28일에 개교하였다. exam_date.csv를 만들어 date이라는 column을 만든 후 첫 번째 원소는 1936년 4월 28일에 해당하는 data를 입력하고, 두 번째 원소는 2022년 6월 10일을 나타내는 data를 입력한다.
이 csv 파일을 읽어서 pandas를 이용하여 1936년 4월 28일이 무슨 요일인지 출력하고, 시험을 보는 오늘 기준으로 몇 일이 지났는지 출력하는 코드를 작성하시오.
(기록자 주: 몇 일*은 비문이고 며칠이라고 쓰는 게 맞음)
'''

import numpy as np
import pandas as pd

df = pd.DataFrame({
    "date": ["1936-04-28",
            "2022-06-10"]
})

df.to_csv("exam_date.csv", index=False)
dpath = "../exam_date.csv"

date_csv = pd.read_csv(dpath)
date_csv["date"] = pd.to_datetime(date_csv["date"])

wd = date_csv["date"].iloc[0:1].dt.weekday.values
if wd == 0:
    print("월요일")
elif wd == 1:
    print("화요일")
elif wd == 2:
    print("수요일")
elif wd == 3:
    print("목요일")
elif wd == 4:
    print("금요일")
elif wd == 5:
    print("토요일")
else:
    print("일요일")

print(date_csv["date"].max() - date_csv["date"].min())

'''
# 출력 결과
화요일
31454 days 00:00:00
'''
