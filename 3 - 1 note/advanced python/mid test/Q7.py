# 7번 : 코드 완성
def sol(n):
    # 자연수의 자릿수의 합
    ans = 0
    while True:
        ans += n % 10
        n //= 10
        if n == 0:
            break
    return ans

test_lam = list(range(300))
fil_lam = list(filter(lambda x : x % 10 == (x % 100) // 10, test_lam))
map_lam = list(map(sol, fil_lam))
print(map_lam)