def dict_cube():
    values = {'1': '', '2': '', '3': '', '4': '', '5': '', }
    for i in values.keys():
        values.update({i: (int(i) ** 3)})
    return values


print(dict_cube())
