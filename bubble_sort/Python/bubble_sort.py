def bubble_sort(arr):
    length = len(arr)
    for i in range(length):
        for j in range(0, length - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def main():
    random_list = [12, 4, 5, 6, 25, 14, 15]
    bubble_sort(random_list)
    print(random_list)

if __name__ == "__main__":
    main()