def is_armstrong_number(number):
    number_to_str = str(number)

    total_sum = sum(int(digit) ** len(number_to_str) for digit in number_to_str)

    return total_sum == number