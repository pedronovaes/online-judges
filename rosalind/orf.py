# Not all DNA will be transcribed into RNA: so-called junk DNA appears to have
# no practical purpose for cellular function. So, we can begin translation at
# any position along a strand of RNA, meaning that any substring of a DNA
# string can serve as a template for translation, as long as it begins with a
# start codon, ends with a stop codon, and has no other stop codons in the
# middle

import sys
import re
from revc import reverse_complement

DNA_CODON_TABLE = {
    'F': ['TTT', 'TTC'],
    'L': ['CTT', 'CTC', 'TTA', 'CTA', 'TTG', 'CTG'],
    'I': ['ATT', 'ATC', 'ATA'], 'V': ['GTT', 'GTC', 'GTA', 'GTG'],
    'M': ['ATG'],
    'S': ['TCT', 'TCC', 'TCA', 'TCG', 'AGT', 'AGC'],
    'P': ['CCT', 'CCC', 'CCA', 'CCG'],
    'T': ['ACT', 'ACC', 'ACA', 'ACG'],
    'A': ['GCT', 'GCC', 'GCA', 'GCG'],
    'Y': ['TAT', 'TAC'],
    'H': ['CAT', 'CAC'],
    'N': ['AAT', 'AAC'],
    'D': ['GAT', 'GAC'],
    'STOP': ['TAA', 'TAG', 'TGA'],
    'Q': ['CAA', 'CAG'],
    'K': ['AAA', 'AAG'],
    'E': ['GAA', 'GAG'],
    'C': ['TGT', 'TGC'],
    'R': ['CGT', 'CGC', 'CGA', 'AGA', 'CGG', 'AGG'],
    'G': ['GGT', 'GGC', 'GGA', 'GGG'],
    'W': ['TGG']
}

# An open reading frame (ORF) is one which starts from the start codon (ATG)
# and ends by stop codon (TAA, TAG, or TGA), without any other stop codons in
# between
def find_open_reading_frame(dna):
    orf = []

    # p = re.findall(pattern='(?=(ATG(?:...)*?)(?=TAG|TGA|TAA))', string=dna)
    p = re.finditer(pattern='ATG', string=dna)

    for match in p:
        subdna = dna[match.start():]
        codons = re.findall(pattern='.{1,3}', string=subdna)

        frame = ''
        for codon in codons:
            if codon not in DNA_CODON_TABLE['STOP']:
                frame += codon
            else:
                frame += codon
                orf.append(frame)
                break

    return orf


def dna_to_protein(dna):
    prot = ''

    # Breaking the DNA into codons
    codons = re.findall(pattern='.{1,3}', string=dna)

    for codon in codons:
        for aminoacid in DNA_CODON_TABLE:
            if codon in DNA_CODON_TABLE[aminoacid]:
                if aminoacid != 'STOP':
                    prot += aminoacid
                else:
                    break

    return prot


if __name__ == '__main__':
    dna = ''.join(sys.stdin.read().split('\n')[1:])

    ofr = []

    ofr.extend(find_open_reading_frame(dna=dna))
    ofr.extend(find_open_reading_frame(dna=reverse_complement(dna=dna)))

    proteins = []

    for frame in ofr:
        protein = dna_to_protein(dna=frame)
        proteins.append(protein)

    for prot in set(proteins):
        print(prot)
