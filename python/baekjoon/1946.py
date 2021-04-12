import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    doc_score = []
    interview_score = []

    for i in range(n):
        a, b = map(int, input().split())
        doc_score.append(a)
        interview_score.append(b)

    interview_score = [x for _, x in sorted(zip(interview_score, doc_score))]

    min_rank = 1e9
    ans = 0
    for x in interview_score:
        if x < min_rank:
            min_rank = x
            ans += 1
    print(ans)
