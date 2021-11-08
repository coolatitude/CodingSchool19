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
                19: [Moves.U, Moves.U],
                21: [Moves.R, Moves.R],
                25: [Moves.D, Moves.D],
                23: [Moves.L, Moves.L]
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
            print('Error finding place found for colors ' + match_color1 + ' and ' + match_color2)
            exit()
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
            cube.add_moves({
                18: [Moves.U2, Moves.L, Moves.U2, Moves.BL],
                20: [Moves.R2, Moves.U, Moves.R2, Moves.BU],
                26: [Moves.D2, Moves.R, Moves.D2, Moves.BR],
                24: [Moves.L2, Moves.D, Moves.L2, Moves.BD],
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
            cube.add_moves({
                18: [Moves.BU, Moves.L, Moves.U, Moves.BL],
                20: [Moves.BR, Moves.U, Moves.R, Moves.BU],
                26: [Moves.BD, Moves.R, Moves.D, Moves.BR],
                24: [Moves.BL, Moves.D, Moves.L, Moves.BD]
            }[place])
        else:
            moves = {
                18: [Moves.BL, Moves.BB, Moves.L],
                20: [Moves.BU, Moves.BB, Moves.U],
                26: [Moves.BR, Moves.BB, Moves.R],
                24: [Moves.BD, Moves.BB, Moves.D],
                15: [Moves.U, Moves.B, Moves.BU],
                36: [Moves.R, Moves.B, Moves.BR],
                29: [Moves.D, Moves.B, Moves.BD],
                8: [Moves.L, Moves.B, Moves.BL],
                2: [Moves.BL, Moves.BB, Moves.L],
                17: [Moves.BU, Moves.BB, Moves.U],
                42: [Moves.BR, Moves.BB, Moves.R],
                27: [Moves.BD, Moves.BB, Moves.D],
            }
            cube.add_moves(moves[found_place])
            bring_corner_here(place, match_color1, match_color2)

    places = [
        (cube.corners[0], Faces.L, Faces.U),
        (cube.corners[1], Faces.U, Faces.R),
        (cube.corners[2], Faces.R, Faces.D),
        (cube.corners[3], Faces.D, Faces.L)
    ]
    while not all([ cube.grid[place[0][0]] == Faces.F and cube.grid[place[0][1]] == place[1] and cube.grid[place[0][2]] == place[2] for place in places]):
        for place in places:
            if not (cube.grid[place[0][0]] == Faces.F and cube.grid[place[0][1]] == place[1] and cube.grid[place[0][2]] == place[2]):
                bring_corner_here(place[0][0], place[1], place[2])


def do_second_layer(cube: Cube):

    class Place:
        def __init__(self, target, opposite, target_color, opposite_color):
            self.opposite_color = opposite_color
            self.target_color = target_color
            self.opposite = opposite
            self.target = target
            self.colors = [target_color, opposite_color]

        def is_correct(self):
            return cube.grid[self.target] == self.target_color and cube.grid[self.opposite] == self.opposite_color

        def order(self):
            possible_places_second_level = [
                (12, 37),
                (43, 30),
                (32, 7),
                (1, 14),
            ]
            for possible_place in possible_places_second_level:
                if cube.grid[possible_place[0]] in self.colors and cube.grid[possible_place[1]] in self.colors:
                    moves = {
                        (12, 37): [Moves.R, Moves.BB, Moves.BR, Moves.U, Moves.BR, Moves.BU, Moves.R],
                        (43, 30): [Moves.D, Moves.BB, Moves.BD, Moves.R, Moves.BD, Moves.BR, Moves.D],
                        (32, 7): [Moves.L, Moves.BB, Moves.BL, Moves.D, Moves.BL, Moves.BD, Moves.L],
                        (1, 14): [Moves.U, Moves.BB, Moves.BU, Moves.L, Moves.BU, Moves.BL, Moves.U]
                    }
                    cube.add_moves(moves[possible_place])
                    break
            possible_places_third_level = [
                (10, 46),
                (39, 50),
                (34, 52),
                (5, 48),
            ]
            for possible_place in possible_places_third_level:
                if cube.grid[possible_place[0]] in self.colors and cube.grid[possible_place[1]] in self.colors:
                    match = {
                        12: 5,
                        43: 10,
                        32: 39,
                        1: 34,
                        37: 34,
                        30: 5,
                        7: 10,
                        14: 39
                    }
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
                    rotate_order = [10, 39, 34, 5]
                    if cube.grid[possible_place[0]] == self.target_color:
                        rotations = rotate_order.index(possible_place[0]) - rotate_order.index(match[self.target])
                        move = Moves.BB if rotations < 0 else Moves.B
                        cube.add_moves([move] * abs(rotations))
                        cube.add_moves(moves[self.target])
                    else:
                        rotations = rotate_order.index(possible_place[0]) - rotate_order.index(match[self.opposite])
                        move = Moves.BB if rotations < 0 else Moves.B
                        cube.add_moves([move] * abs(rotations))
                        cube.add_moves(moves[self.opposite])
                    break

    places = [
        Place(
            12, 37, Faces.U, Faces.R
        ),
        Place(
            43, 30, Faces.R, Faces.D
        ),
        Place(
            32, 7, Faces.D, Faces.L
        ),
        Place(
            1, 14, Faces.L, Faces.U
        )
    ]
    for place in places:
        if not place.is_correct():
            place.order()


def do_top_cross(cube: Cube):
    def orient_cross():
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

    def order_cubies():
        # R U2 R' U' R U' R'
        expected_order = [Faces.R, Faces.U, Faces.L, Faces.D, Faces.R, Faces.U, Faces.L, Faces.D]
        actual_order = list(map(lambda x: cube.grid[x], [39, 10, 5, 34, 39, 10, 5, 34]))

        moves = {
            -Faces.R: [Moves.D, Moves.B2, Moves.BD, Moves.BB, Moves.D, Moves.BB, Moves.BD],
            -Faces.U: [Moves.R, Moves.B2, Moves.BR, Moves.BB, Moves.R, Moves.BB, Moves.BR],
            -Faces.L: [Moves.U, Moves.B2, Moves.BU, Moves.BB, Moves.U, Moves.BB, Moves.BU],
            -Faces.D: [Moves.L, Moves.B2, Moves.BL, Moves.BB, Moves.L, Moves.BB, Moves.BL],
            Faces.R: [Moves.BU, Moves.BB, Moves.BB, Moves.U, Moves.B, Moves.BU, Moves.B, Moves.U],
            Faces.U: [Moves.BL, Moves.BB, Moves.BB, Moves.L, Moves.B, Moves.BL, Moves.B, Moves.L],
            Faces.L: [Moves.BD, Moves.BB, Moves.BB, Moves.D, Moves.B, Moves.BD, Moves.B, Moves.D],
            Faces.D: [Moves.BR, Moves.BB, Moves.BB, Moves.R, Moves.B, Moves.BR, Moves.B, Moves.R]
        }
        for index in range(0, 4):
            color_pos = 0
            while actual_order[color_pos] != expected_order[index]:
                color_pos += 1
            if actual_order[color_pos + 1] == expected_order[index + 1]:
                if actual_order[color_pos + 2] == expected_order[index + 2]:
                    if actual_order[color_pos + 3] == expected_order[index + 3]:
                        # just rotate index time B'
                        pass
                    else:
                        # arrange then rotate
                        # TODO arrange
                        print('HEY')
                elif actual_order[color_pos + 3] == expected_order[index + 2]:
                    # arrange from color pos + 3 perspective
                    cube.add_moves(moves[expected_order[index + 3]])
                    cube.print()
                cube.add_moves([Moves.BB] * (1 + index))
                break
            elif actual_order[color_pos + 2] == expected_order[index + 2]:
                cube.add_moves(moves[expected_order[index + 3]])
                cube.add_moves(moves[expected_order[index + 2]])
                cube.add_move(Moves.BB)
                break
        cube.add_moves([Moves.BB] * [Faces.R, Faces.D, Faces.L, Faces.U].index(cube.grid[39]))

    orient_cross()
    order_cubies()


def do_top_corners(cube: Cube):

    corners = [45, 47, 53, 51]

    def place_top_corners():
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

        def get_cube_number(number):
            colors_tested = list(map(lambda x: cube.grid[x], corner_places[number][0]))
            for corner_tested in corners:
                expected_colors = corner_places[corner_tested][1]
                if all([(found in expected_colors) for found in colors_tested]):
                    return corner_tested

        def angles_are_ordered(angles, angle_to_delete):
            angles = list(filter(lambda x: x != angle_to_delete, angles)) * 2
            expected_order = list(filter(lambda x: x != angle_to_delete, corners))
            number_of_angles = len(angles) % 2
            index = angles.index(expected_order[0])
            is_ordered = True
            for i in range(0, number_of_angles):
                if angles[i] != expected_order[index + i]:
                    is_ordered = False
                    break
            return is_ordered

        def no_cuby_at_the_correct_place():
            return all([corners[index] != get_cube_number(corners[index]) for index in range(0, 4)])

        no_cuby_at_the_correct_place()
        while no_cuby_at_the_correct_place():
            cube.add_moves([Moves.BL, Moves.B, Moves.R, Moves.BB, Moves.L, Moves.B, Moves.BR, Moves.BB])

        expected_order = corners * 2
        actual_order = [get_cube_number(corner) for corner in corners]
        double_actual_order = actual_order * 2

        corner_rotations = {
            -45: [Moves.B, Moves.R, Moves.BB, Moves.BL, Moves.B, Moves.BR, Moves.BB, Moves.L],
            -47: [Moves.B, Moves.U, Moves.BB, Moves.BD, Moves.B, Moves.BU, Moves.BB, Moves.D],
            -53: [Moves.B, Moves.L, Moves.BB, Moves.BR, Moves.B, Moves.BL, Moves.BB, Moves.R],
            -51: [Moves.B, Moves.D, Moves.BB, Moves.BU, Moves.B, Moves.BD, Moves.BB, Moves.U],
            45: [Moves.BL, Moves.B, Moves.R, Moves.BB, Moves.L, Moves.B, Moves.BR, Moves.BB],
            47: [Moves.BD, Moves.B, Moves.U, Moves.BB, Moves.D, Moves.B, Moves.BU, Moves.BB],
            53: [Moves.BR, Moves.B, Moves.L, Moves.BB, Moves.R, Moves.B, Moves.BL, Moves.BB],
            51: [Moves.BU, Moves.B, Moves.D, Moves.BB, Moves.U, Moves.B, Moves.BD, Moves.BB]
        }
        for index in range(0, 4):
            if double_actual_order[index] != expected_order[index]:
                continue
            # if the next cuby is at the correct place
            if double_actual_order[index + 1] == expected_order[index + 1]:
                if double_actual_order[index + 2] == expected_order[index + 2]:
                    return
                else:
                    # simple swap ( A B D C )
                    cube.add_moves(corner_rotations[expected_order[index + 3]])
            # if the rest is ordered
            elif angles_are_ordered(actual_order, double_actual_order[index]):
                clockwise = -1 if double_actual_order[index + 2] == expected_order[index + 1] else 1
                cube.add_moves(
                    corner_rotations[
                        clockwise * expected_order[
                            index
                        ]
                    ]
                )
            # if the opposite cuby is at the correct place
            elif double_actual_order[index + 2] == expected_order[index + 2]:
                print('opposite swap')
                print('Error')
                exit()
        cube.add_moves([Moves.BB] * ([get_cube_number(corner) for corner in corners].index(corners[0])))

    def orientate_top_corners():

        class Check:
            def __init__(self, indices, rotation, match):
                self.indices = indices
                self.rotation = rotation
                self.match = match

        moves = {
            Faces.R: {
                Faces.B: [Moves.R, Moves.B2, Moves.BR, Moves.BB, Moves.R, Moves.BB, Moves.BR, Moves.BL, Moves.B2, Moves.L, Moves.B, Moves.BL, Moves.B, Moves.L],
            },
            Faces.U: {
                Faces.B: [Moves.U, Moves.B2, Moves.BU, Moves.BB, Moves.U, Moves.BB, Moves.BU, Moves.BD, Moves.B2, Moves.D, Moves.B, Moves.BD, Moves.B, Moves.D]
            },
            Faces.L: {
                Faces.B: [Moves.L, Moves.B2, Moves.BL, Moves.BB, Moves.L, Moves.BB, Moves.BL, Moves.BR, Moves.B2, Moves.R, Moves.B, Moves.BR, Moves.B, Moves.R]
            },
            Faces.D: {
                Faces.B: [Moves.D, Moves.B2, Moves.BD, Moves.BB, Moves.D, Moves.BB, Moves.BD, Moves.BU, Moves.B2, Moves.U, Moves.B, Moves.BU, Moves.B, Moves.U]
            },
            Faces.B: {
                Faces.R: [Moves.B, Moves.R2, Moves.BB, Moves.BR, Moves.B, Moves.BR, Moves.BB, Moves.BF, Moves.R2, Moves.F, Moves.R, Moves.BF, Moves.R, Moves.F],
                Faces.U: [Moves.B, Moves.U2, Moves.BB, Moves.BU, Moves.B, Moves.BU, Moves.BB, Moves.BF, Moves.U2, Moves.F, Moves.U, Moves.BF, Moves.U, Moves.F],
                Faces.L: [Moves.B, Moves.L2, Moves.BB, Moves.BL, Moves.B, Moves.BL, Moves.BB, Moves.BF, Moves.L2, Moves.F, Moves.L, Moves.BF, Moves.L, Moves.F],
                Faces.D: [Moves.B, Moves.D2, Moves.BB, Moves.BD, Moves.B, Moves.BD, Moves.BB, Moves.BF, Moves.D2, Moves.F, Moves.D, Moves.BF, Moves.D, Moves.F]
            }
        }

        checks = [
            # From R to B
            Check([38, 44], moves[Faces.R][Faces.B], Faces.B),
            # From U to B
            Check([9, 11], moves[Faces.U][Faces.B], Faces.B),
            # From L to B
            Check([0, 6], moves[Faces.L][Faces.B], Faces.B),
            # From D to B
            Check([33, 35], moves[Faces.D][Faces.B], Faces.B),
            # From B to R
            Check([45, 51], moves[Faces.B][Faces.R], Faces.R),
            # From B to U
            Check([45, 47], moves[Faces.B][Faces.U], Faces.U),
            # From B to L
            Check([47, 53], moves[Faces.B][Faces.L], Faces.L),
            # From B to D
            Check([53, 51], moves[Faces.B][Faces.D], Faces.D),
            # opposite sides are blue
            Check([35, 0], [*moves[Faces.D][Faces.B], *moves[Faces.L][Faces.B]], Faces.B),
            Check([44, 9], [*moves[Faces.R][Faces.B], *moves[Faces.U][Faces.B]], Faces.B),
            Check([6, 11], [*moves[Faces.L][Faces.B], *moves[Faces.U][Faces.B]], Faces.B),
            Check([33, 38], [*moves[Faces.D][Faces.B], *moves[Faces.R][Faces.B]], Faces.B),
            # all corner are blue clockwise oriented
            Check([33, 0, 11], [*moves[Faces.B][Faces.L], *moves[Faces.B][Faces.U]], Faces.B),
            Check([0, 11, 44], [*moves[Faces.B][Faces.U], *moves[Faces.B][Faces.R]], Faces.B),
            Check([11, 44, 33], [*moves[Faces.B][Faces.R], *moves[Faces.B][Faces.D]], Faces.B),
            Check([44, 33, 0], [*moves[Faces.B][Faces.D], *moves[Faces.B][Faces.L]], Faces.B),
            # all corner are blue counter-clockwise oriented
            Check([38, 9, 6], [*moves[Faces.B][Faces.U], *moves[Faces.B][Faces.L]], Faces.B),
            Check([35, 38, 9], [*moves[Faces.B][Faces.R], *moves[Faces.B][Faces.U]], Faces.B),
            Check([6, 35, 38], [*moves[Faces.B][Faces.D], *moves[Faces.B][Faces.R]], Faces.B),
            Check([9, 6, 35], [*moves[Faces.B][Faces.L], *moves[Faces.B][Faces.D]], Faces.B),
        ]
        while not all([cube.grid[corner] == Faces.B for corner in corners]):
            for check in checks:
                if all([cube.grid[x] == check.match for x in check.indices]):
                    cube.add_moves(check.rotation)

    place_top_corners()
    orientate_top_corners()


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
