# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 29/09/2019
# 	Problem: Cyclical figurate numbers
# 	Approach:
#		- Generate 6 dictionarys, each one a sequence(triangular, square, ...) from 1000 to 9999
# 			with the tuple (x, [y1, y2]), where x is the first two digits and yi the last digits of every number with x in the beggining
# 		- Backtrack all valid combinations where the end of one number is the begging of another, avoiding repetions os sets
#		
# **************************************************************************/


def t(i):
    return (i*(i+1))/2

def s(i):
    return i*i

def p(i):
    return (i*(3*i-1))/2

def x(i):
    return i*(2*i-1)

def h(i):
    return (i*(5*i-3))/2

def o(i):
    return (i*(3*i-2))

def find_sequence(f, begin ,end):
    numbers = {}
    for i in range(begin, end):
        k = f(i)
        a = k//100
        b = k%100
        if b > 9:
            numbers.setdefault(a, []).append(b)

    return numbers

def test_sequence(s):
    # the first element must be equal to the last
    if s[0] != s[len(s)-1]:
        return False
    # No repeated elements
    else:
        copy = sorted(s)
        for i in range(len(s)-4):
            if copy[i] == copy[i+3]:
                return False
        
    return True

def recursion(pos, path, sequences, ans):
    path.append(pos[0])
    for i in pos[1]:
        path.append(i)

        if len(path) == 12 and  test_sequence(path):
            ans = path[:]
            return ans

        copy = sequences[:]
        for sub_sequence in sequences:
            if i in sub_sequence:
                copy.remove(sub_sequence)
                ans = recursion((i, sub_sequence[i]), path, copy, ans)
                copy.append(sub_sequence)
        path.pop()
    path.pop()

    return ans


def main():
    tri = find_sequence(t, 45, 141)
    sq = find_sequence(s, 32, 100)
    pent = find_sequence(p, 26, 82)
    hex = find_sequence(x, 23, 71)
    hep = find_sequence(h, 21, 64)
    oct = find_sequence(o, 19, 59)

    conj = []
    conj.append(sq)
    conj.append(pent)
    conj.append(hex)
    conj.append(hep)
    conj.append(oct)

    path = []
    ans = []
    for i,j in tri.items():
        del path[:]
        r = recursion((i, j), path, conj, ans)
        if(len(r) == 12):
            sum_ = 0
            for k in range(0, len(r), 2):
                sum_ += r[k]*100
                sum_ += r[k+1]
            print("Sequence = ", r)
            print("Sum = ", sum_)
            exit()


if __name__ == "__main__":
    main()