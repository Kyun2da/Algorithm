'''
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
'''


def two(s):
    tmp = ""
    for i in s:
        if 'a' <= i <= 'z' or '0' <= i <= '9' or i == '-' or i == '_' or i == '.':
            tmp += i
    return tmp


def three(s):
    tmp = ""
    length = len(s)
    for i, v in enumerate(s):
        if v == '.' and i < length-1 and v == s[i + 1]:
            continue
        else:
            tmp += v
    return tmp


def four(s):
    tmp = ""
    length = len(s)
    for i, v in enumerate(s):
        if (i == 0 and v == '.') or (i == length - 1 and v == '.'):
            continue
        else:
            tmp += v
    return tmp


def solution(new_id):
    new_id = new_id.lower()

    new_id = two(new_id)
    new_id = three(new_id)
    new_id = four(new_id)
    if new_id == "":
        new_id = "a"
    if len(new_id) >= 16:
        new_id = new_id[:15]
    new_id = four(new_id)
    if len(new_id) <= 2:
        while len(new_id) != 3:
            new_id += new_id[-1]
    return new_id


# 예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
# 예2	"z-+.^."	"z--"
# 예3	"=.="	"aaa"
# 예4	"123_.def"	"123_.def"
# 예5	"abcdefghijklmn.p"	"abcdefghijklmn"

print(solution("...!@BaT#*..y.abcdefghijklm"))
print(solution("z-+.^."))


'''
깔끔한 풀이

def solution(new_id):
    answer = ''
    # 1
    new_id = new_id.lower()
    # 2
    for c in new_id:
        if c.isalpha() or c.isdigit() or c in ['-', '_', '.']:
            answer += c
    # 3
    while '..' in answer:
        answer = answer.replace('..', '.')
    # 4
    if answer[0] == '.':
        answer = answer[1:] if len(answer) > 1 else '.'
    if answer[-1] == '.':
        answer = answer[:-1]
    # 5
    if answer == '':
        answer = 'a'
    # 6
    if len(answer) > 15:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]
    # 7
    while len(answer) < 3:
        answer += answer[-1]
    return answer
'''