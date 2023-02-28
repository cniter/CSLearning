# -*- coding: utf-8 -*-
#!/usr/bin/env python

# 压缩区间
def weld_interval(rngs, eps=1E-5):
    pop_idxes = []
    for i, rng in enumerate(rngs):
        if rng[1]-rng[0] <= eps:
            pop_idxes.append(i)
            if i > 0:
                rngs[i-1][1] = rng[1]
                continue
            if i < len(rngs)-1:
                rngs[i+1][0] = rng[0]
                continue
    
    pop_idxes.reverse()
    for i in pop_idxes:
        rngs.pop(i)
    
    return rngs

def weld_interval_target(rngs, target_idx, eps=1E-5):
    pop_idxes = []
    for i, rng in enumerate(rngs):
        if rng[1]-rng[0] <= eps:
            pop_idxes.append(i)
            if i > target_idx:
                rngs[target_idx][1] = rng[1]
                continue
            if i < target_idx:
                rngs[target_idx][0] = rng[0]
                continue
    
    pop_idxes.reverse()
    for i in pop_idxes:
        rngs.pop(i)
    
    return rngs
        

# 区间更新
def update_interval(rngs, start, end, eps=1E-5):
    res_rngs = []
    insert_idx = -1
    for rng in rngs:
        if rng[1] <= start or rng[0] >= end:
            res_rngs.append(rng)
            continue
        if rng[0] <= start:
            if rng[0] != start:
                res_rngs.append([rng[0], start])
            res_rngs.append([start, end])
            insert_idx = len(res_rngs)-1
        if end < rng[1]:
            res_rngs.append([end, rng[1]])
    
    if not res_rngs:
        res_rngs.append([start, end])
        insert_idx = 0

    weld_interval_target(res_rngs, insert_idx, eps)

    return res_rngs

def update_interval_test():
    a = [[1,2],[2,3],[3,4]]
    for item in [[3.5,3.7], [2.0000001,2.999999]]:
        a = update_interval(a, item[0], item[1])
    print(a)
    print(update_interval([[1,2],[2,3],[3,4]], 2.0000001,2.999999))

update_interval_test()