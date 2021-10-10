from cube import Cube, Faces, Moves

# utils
import config


def find_edge(cube, color, match):
    for key in cube.edges.keys():
        if cube.grid[key] == color and match == cube.grid[cube.edges[key]]:
            return key
    return -1


def do_bottom_cross(cube: Cube):

    bottom_edges = [19, 21, 25, 23]

    def bring_edge_here(match_color, place):
        position_found = find_edge(cube, Faces.F, match_color)
        # in face B
        # TODO test this one
        back_order = [50, 46, 48, 52]
        if position_found in back_order:
            up_down_match = {
                19: 46,
                21: 50,
                25: 52,
                23: 48
            }[place]
            for x in range((back_order.index(up_down_match) + 4 - back_order.index(position_found)) % 4):
                cube.add_move(Moves.B)
            cube.add_moves({
                19: [Moves.U * 2],
                21: [Moves.R * 2],
                25: [Moves.D * 2],
                23: [Moves.L * 2]
            }[place])
        # in face B inverted (front color not in on B)
        if cube.edges[position_found] in back_order:
            up_down_match = {
                19: 46,
                21: 50,
                25: 52,
                23: 48
            }[place]
            for x in range((back_order.index(up_down_match) + 4 - back_order.index(cube.edges[position_found])) % 4):
                cube.add_move(Moves.B)
            cube.add_moves({
                19: [Moves.U, Moves.F, Moves.BR, Moves.BF],
                21: [Moves.R, Moves.F, Moves.BD, Moves.BF],
                25: [Moves.D, Moves.F, Moves.BL, Moves.BF],
                23: [Moves.L, Moves.F, Moves.BU, Moves.BF]
            }[place])
        # in the front face already but not at the correct position
        front_order = [19, 21, 25, 23]
        if position_found in front_order:
            cube.add_move({
                19: Moves.U,
                21: Moves.R,
                25: Moves.D,
                23: Moves.L
            }[position_found])
            bring_edge_here(match_color, place)
        # in the front face already but not at the correct orientation
        if cube.edges[position_found] in front_order:
            cube.add_move({
                19: Moves.U,
                21: Moves.R,
                25: Moves.D,
                23: Moves.L
            }[cube.edges[position_found]])
            bring_edge_here(match_color, place)
        # in the rest of the places at the level of the second ring
        ring_order = [1, 12, 43, 32]
        if position_found in ring_order:
            expected_places = {
                1: 19,
                12: 21,
                43: 25,
                32: 23
            }
            expected_place = expected_places[position_found]
            count = (bottom_edges.index(expected_place) + 4 - bottom_edges.index(place)) % 4
            for i in range(count):
                cube.add_move(Moves.F)
            cube.add_move({
                              19: Moves.BU,
                              21: Moves.BR,
                              25: Moves.BD,
                              23: Moves.BL
                          }[expected_place])
            for i in range(count):
                cube.add_move(Moves.BF)
        if cube.edges[position_found] in ring_order:
            expected_places = {
                37: 19,
                30: 21,
                7: 25,
                14: 23
            }
            expected_place = expected_places[position_found]
            count = (bottom_edges.index(expected_place) + 4 - bottom_edges.index(place)) % 4
            for i in range(count):
                cube.add_move(Moves.F)
            cube.add_move({
                              19: Moves.U,
                              21: Moves.R,
                              25: Moves.D,
                              23: Moves.L
                          }[expected_place])
            for i in range(count):
                cube.add_move(Moves.BF)

    places = [
        (19, 16, Faces.U),
        (21, 41, Faces.R),
        (25, 28, Faces.D),
        (23, 3, Faces.L)
    ]

    for place in places:
        if not (cube.grid[place[0]] == Faces.F and cube.grid[place[1]] == place[2]):
            bring_edge_here(place[2], place[0])


def do_bottom_corners(cube: Cube):

    def bring_corner_here(place, match_color1, match_color2):
        found_place = -1
        for corner in cube.corners:
            if cube.grid[corner[0]] == Faces.F and cube.grid[corner[1]] == match_color1 and cube.grid[corner[2]] == match_color2:
                found_place = corner[0]
                break
            elif cube.grid[corner[1]] == Faces.F and cube.grid[corner[2]] == match_color1 and cube.grid[corner[0]] == match_color2:
                found_place = corner[1]
                break
            elif cube.grid[corner[2]] == Faces.F and cube.grid[corner[0]] == match_color1 and cube.grid[corner[1]] == match_color2:
                found_place = corner[2]
                break
        if found_place == -1:
            return
        a = [45, 47, 53, 51]
        b = [38, 35, 6, 9]
        c = [44, 33, 0, 11]
        # else
        if found_place in a:
            matching_place = {
                18: 45,
                20: 51,
                26: 53,
                24: 47
            }
            m = matching_place[place]
            while cube.grid[m] != Faces.F or cube.grid[cube.corners_expanded[m][0]] != match_color1:
                cube.add_move(Moves.B)
                cube.do_moves()
            cube.add_moves({
                18: [],
                20: [],
                26: [],
                24: []
            }[place])
        elif found_place in b:
            matching_place = {
                18: 9,
                20: 38,
                26: 35,
                24: 6
            }
            m = matching_place[place]
            while cube.grid[m] != Faces.F or cube.grid[cube.corners_expanded[m][0]] != match_color1:
                cube.add_move(Moves.B)
            cube.add_moves({
                18: [Moves.L, Moves.BU, Moves.BL, Moves.U],
                20: [Moves.U, Moves.BR, Moves.BU, Moves.R],
                26: [Moves.R, Moves.BD, Moves.BR, Moves.D],
                24: [Moves.D, Moves.BL, Moves.BD, Moves.L]
            }[place])
        elif found_place in c:
            matching_place = {
                18: 0,
                20: 11,
                26: 44,
                24: 33
            }
            m = matching_place[place]
            while cube.grid[m] != Faces.F or cube.grid[cube.corners_expanded[m][0]] != match_color1:
                cube.add_move(Moves.B)
                cube.do_moves()
            cube.add_moves({
                18: [Moves.BU, Moves.L, Moves.U, Moves.BL],
                20: [Moves.BR, Moves.U, Moves.R, Moves.BU],
                26: [Moves.BD, Moves.R, Moves.D, Moves.BR],
                24: [Moves.BL, Moves.D, Moves.L, Moves.BD]
            }[place])
        else:
            if found_place in cube.corners[0]:
                cube.add_moves([Moves.BL, Moves.BB, Moves.L])
            elif found_place in cube.corners[1]:
                cube.add_moves([Moves.BU, Moves.BB, Moves.U])
            elif found_place in cube.corners[2]:
                cube.add_moves([Moves.BR, Moves.BB, Moves.R])
            elif found_place in cube.corners[3]:
                cube.add_moves([Moves.BD, Moves.BB, Moves.D])
            bring_corner_here(place, match_color1, match_color2)


    places = [
        (cube.corners[0], Faces.L, Faces.U),
        (cube.corners[1], Faces.U, Faces.R),
        (cube.corners[2], Faces.R, Faces.D),
        (cube.corners[3], Faces.D, Faces.L)
    ]

    for place in places:
        if not (cube.grid[place[0][0]] == Faces.F and cube.grid[place[0][1]] == place[1] and cube.grid[place[0][2]] == place[2]):
            bring_corner_here(place[0][0], place[1], place[2])


def do_second_layer(cube: Cube):

    def bring_edge_here(place):
        moves = {
                12: [Moves.R, Moves.BB, Moves.BR, Moves.U, Moves.BR, Moves.BU, Moves.R],
                43: [Moves.D, Moves.BB, Moves.BD, Moves.R, Moves.BD, Moves.BR, Moves.D],
                32: [Moves.L, Moves.BB, Moves.BL, Moves.D, Moves.BL, Moves.BD, Moves.L],
                1: [Moves.U, Moves.BB, Moves.BU, Moves.L, Moves.BU, Moves.BL, Moves.U],
                37: [Moves.BU, Moves.B, Moves.U, Moves.BR, Moves.U, Moves.R, Moves.BU],
                30: [Moves.BR, Moves.B, Moves.R, Moves.BD, Moves.R, Moves.D, Moves.BR],
                7: [Moves.BD, Moves.B, Moves.D, Moves.BL, Moves.D, Moves.L, Moves.BD],
                14: [Moves.BL, Moves.B, Moves.L, Moves.BU, Moves.L, Moves.U, Moves.BL]
                           }

        found_position = find_edge(cube, place[1], place[3])
        if found_position in [12, 42, 32, 1, 37, 30, 7, 14]:
            cube.add_moves(moves[found_position])
            found_position = find_edge(cube, place[1], place[3])
        if found_position in [50, 46, 48, 52]:
            place = (place[2], place[3], place[0], place[1])
            found_position = cube.edges[found_position]
        if found_position in [39, 10, 5, 34]:
            match_place = {
                12: 5,
                43: 10,
                32: 39,
                1: 34,
                37: 34,
                30: 5,
                7: 10,
                14: 39
            }[place[0]]
            while not (cube.grid[match_place] == place[1] and cube.grid[cube.edges[match_place]] == place[3]):
                cube.add_move(Moves.B)
            cube.add_moves(moves[place[0]])

    places = [
        (12, Faces.U, 37, Faces.R),
        (43, Faces.R, 30, Faces.D),
        (32, Faces.D, 7, Faces.L),
        (1, Faces.L, 14, Faces.U)
    ]

    for place in places:
        if not (cube.grid[place[0]] == place[1] and cube.grid[place[2]] == place[3]):
            bring_edge_here(place)


def do_top_cross(cube: Cube):
    l = [46, 48, 52, 50]
    all_empty = [i for i in l if cube.grid[i] == Faces.B]
    if len(all_empty) > 0:
        x = next((i for i in l if cube.grid[i] == Faces.B), None)
        y = l[(l.index(x) + 1) % 4]
        if len(all_empty) == 4:
            count = 3
            place = all_empty[0]
        elif len(all_empty) == 2 and (l.index(all_empty[1]) - l.index(all_empty[0])) == 2:
            count = 1
            place = all_empty[0]
        elif len(all_empty) == 2:
            count = 2
            if l.index(all_empty[0]) == 0 and l.index(all_empty[1]) == 3:
                place = all_empty[1]
            else:
                place = all_empty[0]
        else:
            print('Error')
            return

        for i in range(count):
            cube.add_moves({
               48: [Moves.U, Moves.R, Moves.B, Moves.BR, Moves.BB, Moves.BU],
               52: [Moves.L, Moves.U, Moves.B, Moves.BU, Moves.BB, Moves.BL],
               50: [Moves.D, Moves.L, Moves.B, Moves.BL, Moves.BB, Moves.BD],
               46: [Moves.R, Moves.D, Moves.B, Moves.BD, Moves.BB, Moves.BR],
            }[place])
    # TODO ADD MANAGEMENT of misplaced cross edge


def do_top_corners(cube: Cube):
    corner_places = {
        45: [
            [45, 38, 11],
            [Faces.B, Faces.R, Faces.U]
        ],
        47: [
            [47, 9, 0],
            [Faces.B, Faces.U, Faces.L]
        ],
        53: [
            [53, 6, 33],
            [Faces.B, Faces.L, Faces.D]
        ],
        51: [
            [51, 35, 44],
            [Faces.B, Faces.D, Faces.R]
        ]
    }

    def is_correct_angle(corner: int):
        for face in corner_places[corner][0]:
            if not cube.grid[face] in corner_places[corner][1]:
                return False
        return True

    corners = [45, 47, 53, 51]
    correct_corner = 0
    for corner in corners:
        if is_correct_angle(corner):
            correct_corner = corner
            break

    def all_angles_are_correctly_placed():
        for corner in corners:
            if not corner == correct_corner and not is_correct_angle(corner):
                return False
        return True

    corner_rotations = {
        45: [Moves.BL, Moves.B, Moves.R, Moves.BB, Moves.L, Moves.B, Moves.BR, Moves.BB],
        47: [Moves.BD, Moves.B, Moves.U, Moves.BB, Moves.D, Moves.B, Moves.BU, Moves.BB],
        53: [Moves.BR, Moves.B, Moves.L, Moves.BB, Moves.R, Moves.B, Moves.BL, Moves.BB],
        51: [Moves.BU, Moves.B, Moves.D, Moves.BB, Moves.U, Moves.B, Moves.BD, Moves.BB]
    }
    while not all_angles_are_correctly_placed():
        cube.add_moves(corner_rotations[correct_corner])
        cube.do_moves()

    moves = [Moves.BR, Moves.BF, Moves.R, Moves.F]
    while not (cube.grid[45] == Faces.B and cube.grid[47] == Faces.B and cube.grid[53] == Faces.B and cube.grid[51] == Faces.B):
        while not cube.grid[45] == Faces.B:
            cube.add_moves(moves * 2)
            cube.do_moves()
        cube.add_move(Moves.BB)
        cube.do_moves()

    while not cube.grid[44] == Faces.R:
        cube.add_move(Moves.B)
        cube.do_moves()


def solve(cube: Cube):
    if config.verbose:
        print('Solving in progress................................................................')
        cube.print()
    do_bottom_cross(cube)
    if config.verbose:
        print('Cross done.........................................................................')
    do_bottom_corners(cube)
    if config.verbose:
        print('First layer done...................................................................')
    do_second_layer(cube)
    if config.verbose:
        print('Second layer done..................................................................')
    do_top_cross(cube)
    if config.verbose:
        print('Top cross done..................................................................')
    do_top_corners(cube)
    if config.verbose:
        print('Solving done..................................................................')
        print(len(cube.moves_to_print))
    cube.clean_moves()
    if config.verbose:
        print(len(cube.moves_to_print))
    cube.print_moves()
