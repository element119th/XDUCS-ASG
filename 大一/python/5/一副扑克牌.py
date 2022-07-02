
import random
# 创建一副牌
deck = [x for x in range(52)]
# 创建花色和点数
suits = ["Spades", "Hearts", "Diamonds", "Clubs"]
ranks = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"]
# 洗牌
random.shuffle(deck)
# 打印四张牌
for i in range(4):
    suit = suits[deck[i] // 13]
    rank = ranks[deck[i] % 13]
    print("Card number", deck[i], "is the", rank, "of", suit)
