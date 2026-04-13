import pandas as pd
import matplotlib.pyplot as plt

def plot_results():
    df = pd.read_csv("sort_times.csv")
    plt.figure(figsize=(10, 6))

    plt.plot(df['Size'], df['Bubble'], marker='o', label='Bubble Sort')
    plt.plot(df['Size'], df['Insertion'], marker='s', label='Insertion Sort')
    plt.plot(df['Size'], df['Heap'], marker='^', label='Heap Sort')
    plt.plot(df['Size'], df['StdSort'], marker='x', label='std::sort')

    plt.title('Зависимость времени сортировки от размерности массива')
    plt.xlabel('Количество элементов')
    plt.ylabel('Время (мс)')
    plt.xscale('log')
    plt.yscale('log')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("sort_times.png")
    print("График сохранен в sort_times.png")

if __name__ == "__main__":
    plot_results()