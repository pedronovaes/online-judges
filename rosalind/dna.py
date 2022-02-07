import sys

if __name__ == '__main__':
    # A DNA is a string representing the order of nucleobases along one strand
    # of a double-stranded DNA molecule.
    dna = sys.stdin.read()

    # For this problem, I'm using count method because it's a low level C in
    # python, so it's bound to be faster than any loop.
    A = dna.count('A')  # Adenine
    C = dna.count('C')  # Cytosine
    G = dna.count('G')  # Guanine
    T = dna.count('T')  # Thymine

    print(A, C, G, T)