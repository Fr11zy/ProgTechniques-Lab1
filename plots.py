import pandas as pd
import matplotlib.pyplot as plt

def plot_results():
    df = pd.read_csv("sort_times.csv")
    plt.figure(figsize=(10, 6))

    if 'Bubble' in df.columns and (df['Bubble'] != -1).any():
        df_bubble = df[df['Bubble'] != -1]
        plt.plot(df_bubble['Size'], df_bubble['Bubble'], marker='o', label='Bubble Sort')
        
    if 'Insertion' in df.columns and (df['Insertion'] != -1).any():
        df_insert = df[df['Insertion'] != -1]
        plt.plot(df_insert['Size'], df_insert['Insertion'], marker='s', label='Insertion Sort')

    plt.plot(df['Size'], df['Heap'], marker='^', label='Heap Sort')
    plt.plot(df['Size'], df['StdSort'], marker='x', label='std::sort')

    plt.title('Зависимость времени сортировки от размерности массива')
    plt.xlabel('Количество элементов')
    plt.ylabel('Время (мс)')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("sort_times.png")
    print("График сохранен в sort_times.png")

if __name__ == "__main__":
    plot_results()