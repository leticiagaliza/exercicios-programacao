def value_of_card(card):
    """Determine the scoring value of a card.

    :param card: str - given card.
    :return: int - value of a given card.  See below for values.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    return 10 if card in ('K','Q','J') else 1 if card == 'A' else int(card)


def higher_card(card_one, card_two):
    """Determine which card has a higher value in the hand.

    :param card_one, card_two: str - cards dealt in hand.  See below for values.
    :return: str or tuple - resulting Tuple contains both cards if they are of equal value.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    value_1 = 10 if card_one in ('J', 'Q', 'K', '10') else 1 if card_one == 'A' else int(card_one)
    value_2 = 10 if card_two in ('J', 'Q', 'K', '10') else 1 if card_two == 'A' else int(card_two)

    return card_one if value_1 > value_2 else card_two if value_2 > value_1 else (card_one, card_two)

print(higher_card('A','9'))
print(higher_card('8','2'))
print(higher_card('J','K'))
print(higher_card('Q','7'))