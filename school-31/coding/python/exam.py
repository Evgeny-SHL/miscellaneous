for x in range(1, 6):
    for y in range(1, 6):
        for z in range(1, 6):
            for exam in range(1, 6):
                print(x, y, z, round((x + y + z) / 3), exam, sep='	')