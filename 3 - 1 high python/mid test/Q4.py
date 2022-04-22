# 4번 : 파일 입출력
# 강의자료에 첨부된 파일(scores.txt)을 읽어 data에 저장하고, 형식에 맞게 출력.
# 모든 값은 파이썬 내부의 기능을 이용하여 채워야 함

with open("../study-note/3 - 1 high python/mid test/scores.txt", 'r', encoding='utf-8') as file:
    data = file.read().splitlines()

for i in range(1, len(data)):
    line = list(data[i].split())
    name = line[0]
    total = 0
    for num in range(1, len(line)):
        total += int(line[num])
    print("{}의 총점은 {}입니다.".format(name, total))