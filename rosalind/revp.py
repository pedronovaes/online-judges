import sys
from revc import reverse_complement


# A DNA string is a reverse palindrome if it is equal to its reverse complement
def reverse_palindrome(dna):
    return dna == reverse_complement(dna)


if __name__ == '__main__':
    dna = ''.join(sys.stdin.read().split('\n')[1:])

    for i in range(len(dna) - 3):
        for j in range(4, 13):
            if i + j <= len(dna):
                partial_dna = dna[i: i + j]

                if reverse_palindrome(dna=partial_dna):
                    print(i + 1, len(partial_dna))
