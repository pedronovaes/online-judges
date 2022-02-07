import sys


# The reverse complement of a DNA string s is the s^c formed by reversing the
# symbols of s, then taking the complement of each symbol (e.g., the reverse
# complement of "GTCA" is "TGAC").
def reverse_complement(dna):
    # Reverse
    dnar = dna[::-1]

    # Complement
    # Adenine always bonds with thymine, and cytosine always bonds with guanine
    dnarc = dnar.replace('A', 't') \
        .replace('T', 'a') \
        .replace('C', 'g') \
        .replace('G', 'c') \
        .upper()

    return dnarc


if __name__ == '__main__':
    dna = sys.stdin.read()

    dnarc = reverse_complement(dna=dna)
    print(dnarc)
