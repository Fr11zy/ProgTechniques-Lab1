import csv
import random
from datetime import datetime, timedelta

def generate_data(filename, count=100000):
    first_names = ["Иван", "Александр", "Сергей", "Дмитрий", "Алексей", "Михаил", "Николай", "Егор", "Максим"]
    last_names = ["Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев", "Новиков", "Морозов", "Петров"]
    patronymics = ["Иванович", "Александрович", "Сергеевич", "Дмитриевич", "Алексеевич", "Михайлович"]
    
    seats_letters = ['A', 'B', 'C', 'D', 'E', 'F']
    
    start_date = datetime.now()
    
    print(f"Генерация {count} записей в {filename}...")
    
    with open(filename, mode='w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(['FlightDate', 'FlightNumber', 'FullName', 'SeatNumber'])
        
        for _ in range(count):
            random_days = random.randint(0, 365)
            flight_date = (start_date + timedelta(days=random_days)).strftime('%Y-%m-%d')
            
            flight_number = random.randint(100, 9999)
            
            full_name = f"{random.choice(last_names)} {random.choice(first_names)} {random.choice(patronymics)}"
            
            seat_number = f"{random.randint(1, 35)}{random.choice(seats_letters)}"
            
            writer.writerow([flight_date, flight_number, full_name, seat_number])
            
    print("Готово! Данные успешно сгенерированы.")

if __name__ == "__main__":
    generate_data("input.csv", 100000)