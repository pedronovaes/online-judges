import sys
import re
from rna import dna_to_rna
from prot import rna_to_protein


# In the nucleus, an enzyme called RNA polymerase (RNAP) initiates
# transcription by breaking the bonds joining complementary bases of DNA. It is
# not the case that an entire substring of DNA is transcribed into RNA and then
# translated into a peptide one codon at a time. In reality, a pre-mRNA is
# first chopped into smaller segments called introns and exons; for the purpose
# of protein translation, the introns are thrown out, and the exons are glued
# together sequentially to produce a final strand of mRNA
def dna_to_protein(dna, introns):
    for intron in introns:
        dna = dna.replace(intron, '')

    rna = dna_to_rna(dna=dna)
    protein = rna_to_protein(rna=rna)

    return protein


if __name__ == '__main__':
    FASTA = re.split(
        pattern='>Rosalind_[0-9]+',
        string=''.join(sys.stdin.read().split('\n'))
    )[1:]

    dna = FASTA[0]
    introns = FASTA[1:]

    protein = dna_to_protein(dna=dna, introns=introns)
    print(protein)
