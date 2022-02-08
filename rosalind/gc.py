import sys


# The GC-content of a DNA string is given by the percentage of symbols in the
# string that are 'C' or 'G'.
def gc_content(dna):
    len_g = dna.count('G')
    len_c = dna.count('C')

    return round((len_g + len_c) / len(dna) * 100, 6)


if __name__ == '__main__':
    FASTA = ''.join(sys.stdin.read().split('\n'))

    highest_gc_content = 0.0

    for dna in FASTA.split('>')[1:]:
        id = dna[:13]
        dna = dna[13:]

        individual_gc_content = gc_content(dna=dna)

        if individual_gc_content > highest_gc_content:
            highest_gc_content = individual_gc_content
            assoc_id = id

    print(assoc_id)
    print(highest_gc_content)
