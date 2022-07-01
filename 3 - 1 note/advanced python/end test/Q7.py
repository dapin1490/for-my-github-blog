'''
타이타닉 생존자들에게 금전적인 지원을 하려고 한다. 수업시간에 사용한 titanic.csv에서 이용하여 다음에 대한 내용을 수행하도록 코드를 구현하시오.
(1) survived가 1인 사람만 필터링한다.
(2) AgeRough라는 column을 추가하여 나이가 30세 미만인 사람은 1, 30~49세는 2, 50세 이상은 3으로 채워넣고 data가 없는 경우에는 채워넣지 않는다.
(3) CompAgeRough라는 column을 추가하여 AgeRough가 1인 사람에게는 500, 2인 사람에게는 550, 3인 사람에게는 600을 할당한다.
(4) CompAgeRough에 Pclass가 1이면 3을 Pclass가 2면 1.1을 Pclass가 3이면 1을 곱한 data를 CompAgeRoughPclass라는 column을 만들어 집어넣는다.
(5) AgeRough와 CompAgeRough, CompAgeRoughPclass가 추가된 dataframe을 titaniccomp.csv로 저장한다.
'''

import pandas as pd

tipath = "../titanic.csv"
tit = pd.read_csv(tipath)

# (1) 생존자 필터링
surviver = tit.loc[tit["Survived"] == 1]

# (2) "AgeRough"라는 column을 추가하여 30세 미만인 사람은 1, 30~49세는 2, 50세 이상은 3으로 채워넣고, data가 없으면 채우지 않음
surviver["AgeRough"] = None
surviver.loc[surviver["Age"] >= 50, "AgeRough"] = 3
surviver.loc[surviver["Age"] <= 49, "AgeRough"] = 2
surviver.loc[surviver["Age"] < 30, "AgeRough"] = 1

# (3) "CompAgeRough"라는 column을 추가하여 AgeRough가 1인 사람에게는 500, 2인 사람에게는 550, 3인 사람에게는 600을 할당한다
surviver["CompAgeRough"] = None
surviver.loc[surviver["AgeRough"] == 1, "CompAgeRough"] = 500
surviver.loc[surviver["AgeRough"] == 2, "CompAgeRough"] = 550
surviver.loc[surviver["AgeRough"] == 3, "CompAgeRough"] = 600

# (4) CompAgeRough에 Pclass가 1이면 3을 Pclass가 2면 1.1을 Pclass가 3이면 1을 곱한 data를 CompAgeRoughPclass라는 column을 만들어 집어넣는다
surviver["CompAgeRoughPclass"] = None
surviver.loc[surviver["Pclass"] == 1, "CompAgeRoughPclass"] = surviver["CompAgeRough"] * 3
surviver.loc[surviver["Pclass"] == 2, "CompAgeRoughPclass"] = surviver["CompAgeRough"] * 1.1
surviver.loc[surviver["Pclass"] == 3, "CompAgeRoughPclass"] = surviver["CompAgeRough"] * 1

# (5) AgeRough와 CompAgeRough, CompAgeRoughPclass가 추가된 dataframe을 titaniccomp.csv로 저장한다.
surviver.to_csv("titaniccomp.csv", index=False)

surviver.info()

'''
# 출력 결과
<class 'pandas.core.frame.DataFrame'>
Int64Index: 342 entries, 1 to 889
Data columns (total 15 columns):
 #   Column              Non-Null Count  Dtype  
---  ------              --------------  -----  
 0   PassengerId         342 non-null    int64  
 1   Survived            342 non-null    int64  
 2   Pclass              342 non-null    int64  
 3   Name                342 non-null    object 
 4   Sex                 342 non-null    object 
 5   Age                 290 non-null    float64
 6   SibSp               342 non-null    int64  
 7   Parch               342 non-null    int64  
 8   Ticket              342 non-null    object 
 9   Fare                342 non-null    float64
 10  Cabin               136 non-null    object 
 11  Embarked            340 non-null    object 
 12  AgeRough            290 non-null    object 
 13  CompAgeRough        290 non-null    object 
 14  CompAgeRoughPclass  290 non-null    object 
dtypes: float64(2), int64(5), object(8)
memory usage: 50.9+ KB
'''
