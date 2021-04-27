import argparse

from cube import Cube
from algorythm import solve

ap = argparse.ArgumentParser()
ap.add_argument('-v', '--verbose', required=False, const=True, default=False, nargs='?')
ap.add_argument('-s', '--size', required=False, default=3)
ap.add_argument('moves', metavar='M', type=str, nargs='*', default=[],
                help='the list of the moves to apply')

args = vars(ap.parse_args())

verbose = args['verbose']


def main():
    cube = Cube(args['size'])
    if args['verbose']:
        cube.print()
    for move in args['moves']:
        cube.do_move(move)
        if args['verbose']:
            cube.print()
    solve(cube)


main()
