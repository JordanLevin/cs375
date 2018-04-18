import random

def write_file(data, name):
    with open('tests/' + name, 'w+') as f:
        for item in data:
            f.write(str(item[0]) + ',' + str(item[1]) + '\n')


def main():
    data = []
    num = input('enter test case amount: ')
    for _ in range(int(num)):
        test = []
        count = random.randint(1,5)
        weight = random.randint(5,25)
        test.append((count, weight))
        for _ in range(count):
            w = random.randint(1, weight//2)
            p = random.randint(5,30)
            test.append((w, p))
        data.append(test)

    for k, test in enumerate(data):
        write_file(test, 'input' + str(k) + '.txt')
    

main()
