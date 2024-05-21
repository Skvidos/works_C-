def calculate_veniki(N, m, k):
    # Расчет количества произведенных веников
    total_veniki = N // m  # Целая часть от деления
    return total_veniki


def calculate_unused_hvostin(N, m, k):
    # Расчет количества не бракованных хворостин, которые останутся неиспользованными
    brakovka = N // k  # Определение количества бракованных хворостин
    # Получение общего количества веников
    total_veniki = calculate_veniki(N, m, k)
    used_hvostin = total_veniki * m  # Определение количества использованных хворостин
    # Определение количества неиспользованных хворостин
    unused_hvostin = N - used_hvostin - brakovka
    return unused_hvostin


# Параметры для функций
N = 1500  # Общее количество хворостин
m_min = 20  # Минимальное количество хворостин на веник
m_max = 30  # Максимальное количество хворостин на веник
k = 5  # Каждая k-я хворостина бракуется

# Вызов функций для получения результатов
total_veniki_produced = calculate_veniki(N, m_max, k)
unused_hvostin_remaining = calculate_unused_hvostin(N, m_max, k)

print("Количество произведенных веников:", total_veniki_produced)
print("Количество неиспользованных хворостин:", unused_hvostin_remaining)
