from dataclasses import dataclass
from enum import Enum
import random
import time

CLIENTS_COUNT = 30
MAX_TRANSACTIONS_COUNT = 20
MIN_TRANSACTION_COUNT = 1

TIME_FORMAT = '%d.%m.%y %H:%M:%S'

# There are no women 0_o
SURNAMES = [
    "Маташков", "Иванов", "Смирнов", "Кузнецов", "Петров", "Соколов", "Новиков", "Фёдоров",
    "Лебедев", "Орлов", "Козлов", "Щукин", "Макаров", "Гусев", "Куликов", "Воробьёв",
    "Морозов", "Зайцев", "Крылов", "Дубинин", "Виноградов"
]
NAMES = ["Артём", "Иван", "Дмитрий", "Максим", "Сергей", "Андрей", "Илья", "Кирилл", "Павел",
         "Марк", "Олег", "Юрий", "Богдан", "Артур", "Семён", "Виктор", "Егор", "Даниил",
         "Борис", "Ярослав", "Александр", "Алексей"]
MIDDLE_NAMES = ["Артёмович", "Иванович", "Дмитриевич", "Максимович", "Сергеевич", "Андреевич", "Ильич", "Кириллович",
                "Павлович", "Маркович", "Олегович", "Юриевич", "Богданович", "Артурович", "Семёнович", "Викторович",
                "Егорович", "Даниилович", "Борисович", "Ярославович", "Александрович", "Алексеевич"]


class TransactionType(str, Enum):
    profit = "Приход"
    los = "Расход"


TRANSACTION_TYPES = [TransactionType.los, TransactionType.profit]


@dataclass
class Transaction:
    date: str
    time: str
    type: TransactionType
    amount: float


@dataclass
class ClientInfo:
    pid: int
    surname: str
    name: str
    middle_name: str
    transactions: list[Transaction]


def random_time(start, end, prop) -> time.struct_time:
    # https://stackoverflow.com/questions/553303/how-to-generate-a-random-date-between-two-other-dates
    stime = time.mktime(time.strptime(start, TIME_FORMAT))
    etime = time.mktime(time.strptime(end, TIME_FORMAT))
    ptime = stime + prop * (etime - stime)
    return time.localtime(ptime)


def get_date_str(t: time.struct_time) -> str:
    return time.strftime("%d.%m.%y", t)


def get_time_str(t: time.struct_time) -> str:
    return time.strftime("%H:%M:%S", t)


def generate_transactions() -> list[Transaction]:
    n = random.randrange(MIN_TRANSACTION_COUNT, MAX_TRANSACTIONS_COUNT+1)
    transactions: list[Transaction] = []
    for _ in range(n):
        t = random_time("01.01.24 00:00:00", "01.01.25 00:00:00", random.random())
        transactions.append(
            Transaction(
                date=get_date_str(t),
                time=get_time_str(t),
                type=random.choice(TRANSACTION_TYPES),
                amount=random.uniform(100.0, 20_000.0)
            )
        )
    return transactions


ids_count = 0


def generate_client() -> ClientInfo:
    global ids_count
    ids_count += 1
    pid = ids_count
    surname = random.choice(SURNAMES)
    name = random.choice(NAMES)
    middle_name = random.choice(MIDDLE_NAMES)
    transactions = generate_transactions()
    return ClientInfo(
        pid=pid,
        surname=surname,
        name=name,
        middle_name=middle_name,
        transactions=transactions
    )


def get_clients() -> list[ClientInfo]:
    clients: list[ClientInfo] = []
    for _ in range(CLIENTS_COUNT):
        clients.append(generate_client())
    random.shuffle(clients)
    return clients


def write_line(file, text: str):
    file.write(text + "\n")
    print(text)


def transaction_line_log_str(transaction: Transaction) -> str:
    return f"{transaction.date}\t{transaction.time}\t{transaction.type.value}\t{transaction.amount:.2f}"

def create_client_log():
    clients = get_clients()
    with open("client_log", "w", encoding="utf-8") as f:
        for client in clients:
            write_line(f, f"{client.pid}")
            write_line(f, f"{client.surname}\t{client.name}\t{client.middle_name}")
            transactions_count = len(client.transactions)
            write_line(f, str(transactions_count))
            for transaction in client.transactions:
                write_line(f, transaction_line_log_str(transaction))


if __name__ == "__main__":
    create_client_log()
