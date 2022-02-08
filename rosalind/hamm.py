import sys


# Given two strings s and t of equal length, the Hamming distance between them
# is the number of corresponding symbols that differ in s and t
def hamming_distance(s, t):
    hd = 0

    for i in range(len(s)):
        if s[i] != t[i]:
            hd += 1

    return hd


if __name__ == '__main__':
    dnas = sys.stdin.read().split('\n')

    hamming = hamming_distance(s=dnas[0], t=dnas[1])
    print(hamming)
