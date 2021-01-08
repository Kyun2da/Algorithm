from collections import deque


def solution(bridge_length, weight, truck_weights):
    leftTruck = deque(truck_weights)
    answer = 0
    q = deque()
    nowTruckWeight = 0
    # 아직 다리를 건널 트럭이 있을때까지 루프
    while leftTruck or q:
        # 트럭이 다리를 다 건넜으면 빼준다.
        if q and q[0][1] == bridge_length:
            nowTruckWeight -= q[0][0]
            q.popleft()
        # 건너지 못한 트럭이있고 다리에 오를수있으면 트럭을 다리에 올린다.
        if leftTruck and nowTruckWeight + leftTruck[0] <= weight and len(q) < bridge_length:
            x = leftTruck.popleft()
            q.append([x, 0])
            nowTruckWeight += x

        for x in range(len(q)):
            q[x][1] += 1
        # print("%d초" % answer)
        # print(q)
        answer += 1

    return answer


print(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]))
