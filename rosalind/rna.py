import sys


def dna_to_rna(dna):
    rna = dna.replace('T', 'U')

    return rna

if __name__ == '__main__':
    # An RNA string is a string that represents the order of nucleobases along
    # a strand of RNA.
    dna = sys.stdin.read()

    rna = dna_to_rna(dna=dna)

    print(rna)