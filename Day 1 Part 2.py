# hacked together. First number is correct answer

with open('day1test.txt') as file:
    line = file.readline()

    # lines = [line.rstrip() for line in lines]

    commands = line.split(",")
    commands = [cmd.strip() for cmd in commands]
    #print(commands)

    thelist = []
    dir = 90
    xpos = 0
    ypos = 0
    thelist.append([0,0])


    for i in commands:
        #handle rotation
        if i[:1] == 'L':
            dir = dir - 90
        elif i[:1] == 'R':
            dir = dir + 90
        else:
            print("error")

        if dir == -90:
            dir = 270
        if dir == 360:
            dir = 0
        #handle moves
        nummoves = int(i[1:])

        if dir == 0:
            for tmp in range(0,nummoves):
                xpos = xpos + 1
                if [xpos, ypos] in thelist:
                    print(abs(xpos) + abs(ypos))
                else:
                    thelist.append([xpos, ypos])
        elif dir == 90:
            for tmp in range(0, nummoves):
                ypos = ypos - 1
                if [xpos, ypos] in thelist:
                    print(abs(xpos) + abs(ypos))
                else:
                    thelist.append([xpos, ypos])
        elif dir == 180:
            for tmp in range(0,nummoves):
                xpos = xpos - 1
                if [xpos, ypos] in thelist:
                    print(abs(xpos) + abs(ypos))
                else:
                    thelist.append([xpos, ypos])
        elif dir == 270:
            for tmp in range(0,nummoves):
                ypos = ypos + 1
                if [xpos, ypos] in thelist:
                    print(abs(xpos) + abs(ypos))
                else:
                    thelist.append([xpos, ypos])
        else:
            print("error")



    distance = abs(xpos)+abs(ypos)
#    print(distance)
#def move(dir, xpos, ypos):
