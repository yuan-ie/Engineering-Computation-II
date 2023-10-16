
def get_filtered(self):

    y = []
    taps = [1.0, 2.0, 3.0]
    input = [1,2,3,4,5]

    for element in y:
        for x in taps[x]:
            for k in range(taps):
                if (k - 1==0):
                    y[element] = y[element] + taps[x]*0
                
                y[element] = y[element] + taps[x]*input
        

'''
note:
    goal for first loop
    if input[x-1] < [0]th index, use zero
    else, use input = 0
    y[element] = y[element] + taps[x]*input
    y[element] = y[element] + taps[x-1]*input
    y[element] = y[element] + taps[x-2]*input


'''