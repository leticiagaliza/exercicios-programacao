def value_of_card(card):
    """Determine the scoring value of a card.

    :param card: str - given card.
    :return: int - value of a given card.  See below for values.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    return 10 if card in 'JQK' else 1 if card == 'A' else int(card)


def higher_card(card_one, card_two):
    """Determine which card has a higher value in the hand.

    :param card_one, card_two: str - cards dealt in hand.  See below for values.
    :return: str or tuple - resulting Tuple contains both cards if they are of equal value.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """
    value_1 = 10 if card_one in 'JQK' else 1 if card_one == 'A' else int(card_one)
    value_2 = 10 if card_two in 'JQK' else 1 if card_two == 'A' else int(card_two)

    return card_one if value_1 > value_2 else card_two if value_2 > value_1 else (card_one, card_two)


def value_of_ace(card_one, card_two):
    """Calculate the most advantageous value for the ace card.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: int - either 1 or 11 value of the upcoming ace card.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """
    value_1 = 10 if card_one in 'JQK' else 1 if card_one == 'A' else int(card_one)
    value_2 = 10 if card_two in 'JQK' else 1 if card_two == 'A' else int(card_two)

    return 1 if any(card == 'A' for card in (card_one, card_two)) else 11 if value_1 + value_2 <= 10 else 1


def is_blackjack(card_one, card_two):
    """Determine if the hand is a 'natural' or 'blackjack'.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: bool - is the hand is a blackjack (two cards worth 21).

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """
    return (card_one == 'A' and card_two in ('J', 'Q', 'K', '10')) or card_two == 'A' and card_one in (
    'J', 'Q', 'K', '10')


def can_split_pairs(card_one, card_two):
    """Determine if a player can split their hand into two hands.

    :param card_one, card_two: str - cards dealt.
    :return: bool - can the hand be split into two pairs? (i.e. cards are of the same value).
    """
    return all(card in ('10', 'J', 'Q', 'K') for card in (card_one, card_two)) or card_one == card_two


def can_double_down(card_one, card_two):
    """Determine if a blackjack player can place a double down bet.

    :param card_one, card_two: str - first and second cards in hand.
    :return: bool - can the hand can be doubled down? (i.e. totals 9, 10 or 11 points).
    """
    value_1 = 10 if card_one in 'JQK' else 1 if card_one == 'A' else int(card_one)
    value_2 = 10 if card_two in 'JQK' else 1 if card_two == 'A' else int(card_two)

    return value_1 + value_2 in (9, 10, 11)