# In terms of the protein's primary structure, the domain is an interval of
# amino acids that can evolve and function independently. Just like species,
# proteins can evolve, forming homologous groups called protein families.
# Proteins from one family usually have the same set of domains, performing
# similar functions. A component of a domain essential for its function is
# called motif, a nucleotide of amino acid pattern of biological significance.

import sys
import requests
import re


def find_motif_from_uniprot(uniprot, motif='(?=(N[^P][ST][^P]))'):
    locations = []

    url = f'http://www.uniprot.org/uniprot/{uniprot}.fasta'
    protein = ''.join(requests.get(url).text.split('\n')[1:-1])

    p = re.finditer(pattern=motif, string=protein)

    for match in p:
        locations.append(str(match.start() + 1))

    return locations


if __name__ == '__main__':
    uniprots = sys.stdin.read().split('\n')

    for uniprot in uniprots:
        locations = find_motif_from_uniprot(uniprot=uniprot)

        if len(locations) > 0:
            print(uniprot)
            print(' '.join(locations))
