class Bank:

    def __init__(self, balance: List[int]):
        self.balance = balance
        self.length = len(self.balance)

    def check_within_limits(self, account: int) -> bool:
        if 1 <= account <= self.length:
            return True
        return False

    def get_balance_index(self, account: int) -> int:
        return account - 1

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if self.check_within_limits(account1) and self.check_within_limits(account2) and self.balance[self.get_balance_index(account1)] >= money:
            self.balance[self.get_balance_index(account2)] += money
            self.balance[self.get_balance_index(account1)] -= money
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if self.check_within_limits(account):
            self.balance[self.get_balance_index(account)] += money
            return True
        return False

    def withdraw(self, account: int, money: int) -> bool:
        if self.check_within_limits(account) and self.balance[self.get_balance_index(account)] >= money:
            self.balance[self.get_balance_index(account)] -= money
            return True
        return False


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)