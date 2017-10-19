#!/usr/bin/env python3

import sys

# mods l, r
def expand(l,r,prefer):
    old_l, old_r = len(l), len(r)
    lpos = rpos = 0
    while lpos < len(l) and rpos < len(r) and lpos+rpos<len(prefer):
        if prefer[-1-lpos-rpos]==l[lpos]:
            lpos += 1
        elif prefer[-1-lpos-rpos]==r[rpos]:
            rpos += 1
        else:
            return False, True
    if lpos+rpos == len(prefer):
        return False, False
    while lpos < len(l) and lpos+rpos<len(prefer):
        if prefer[-1-lpos-rpos] == l[lpos]:
            lpos += 1
        else:
            r.append(prefer[-1-lpos-rpos])
            rpos += 1
    while rpos < len(r) and lpos+rpos<len(prefer):
        if prefer[-1-lpos-rpos] == r[rpos]:
            rpos += 1
        else:
            l.append(prefer[-1-lpos-rpos])
            lpos += 1
    return len(l)!=old_l or len(r)!=old_r, False

## check does not make wierd answer
def valid_pair(l,r,m):
    if len(l)+len(r)<=m:
        return True
    a = l[m-len(r):]
    b = r[m-len(l):]
    b.reverse()
    return a==b

# unit test
# print('valid_pair([1,2,3,4],[6,5,4,3],6):',valid_pair([1,2,3,4],[6,5,4,3],6))
# print('valid_pair([1,2,3,4,5],[5,4,3],6):',valid_pair([1,2,3,4,5],[5,4,3],6))
# print('valid_pair([1,2,3,4,5],[3,5,4],6):',valid_pair([1,2,3,4,5],[3,5,4],6))

def parse(n,m,prefer):
    if m == 0:
        return []
    # determined left and right
    dl = []
    dr = []
    # store equal range
    eq = []
    ret = []

    ## until find something different
    while len(eq)<m:
        cand = list({prefer[i][-1] for i in range(n)})
        if len(cand)>2:
            return None
        elif len(cand)==1:
            eq.append(cand[0])
            for i in range(n):
                prefer[i].pop()
        else:
            cand.sort()
            dl.append(cand[0])
            dr.append(cand[1])

            i, streak = 0, 0
            ## cycle check each prefer[i] untill no expanded
            while streak <= n:
                expanded, failed = expand(dl,dr,prefer[i])
                if failed:
                    return None
                if not expanded:
                    streak += 1
                else:
                    streak = 0
                i = (i+1)%n

            if not valid_pair(dl,dr,len(prefer[0])):
                return None

            while len(dl) + len(dr) > len(prefer[0]):
                dr.pop()

            for i in range(n):
                prefer[i] = prefer[i][:-len(dl)-len(dr)]

            ret = parse(n,len(prefer[0]),prefer)
            print (ret)
            if ret == None:
                return None
            # reverse right determined part
            dr.reverse()
            ret = dl+ret+dr
            break

    if ret == []:
        ret.append(eq.pop())
    while eq:
        element = eq.pop()
        if element < ret[0]:
            ret.insert(0,element)
        else:
            ret.append(element)
    return ret


def sol():
    n, m = (int(_) for _ in input().strip().split())
    prefer = [[int(_) for _ in input().strip().split()] for soc in range(n)]
    result = parse(n,m,prefer)
    if result:
        print(*result,sep=' ')
    else:
        print('Muggles!')

for _ in range(int(input())): sol()
