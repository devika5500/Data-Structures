class StockProfitCalculator(object):
    
    def __init__(self):
        self.proceeds = 0
        self.cost = 0
        self.netProfit = 0
        self.returnOnInvestment = 0
        
    def calculate(self):
        print("--------ENTER INPUTS--------")
        stockSymbol = input('Stock Symbol: ')
        allotment = int(input('Allotment (number of shares): '))
        finalSharePrice =int(input('Final Share Price (in dollars): '))
        sellCommission = int(input('Sell Commission (in dollars): '))
        initialSharePrice = int(input('Initial Share Price (in dollars): '))
        buyCommission = int(input('Buy Commission (in dollars): '))
        taxRate = int(input('Capital Gain Tax Rate (in %): '))
        print("")
        print("--------PROFIT REPORT--------")
        self.calculateProceeds(allotment, finalSharePrice)
        self.calculateCost(allotment, initialSharePrice, sellCommission, buyCommission, taxRate)
        self.calculateNetProfit()
        self.calculateReturnOnInvestment()
        self.calculateBreakEvenPrice(allotment, initialSharePrice, buyCommission, sellCommission)
        decision = input("Start a new Calculation?(y/n): ")
        if(decision == "y"):
            self.calculate()
        else:
            return
	        
    def calculateProceeds(self, allotment, finalSharePrice):
        self.proceeds = allotment*finalSharePrice
        print("Proceeds ")
        print("$", self.proceeds)
        print("")
        
    def calculateCost(self, allotment, initialSharePrice, sellCommission, buyCommission, taxRate):
        purchasePrice = (allotment*initialSharePrice) + buyCommission + sellCommission
        capitalGain = self.proceeds - purchasePrice
        taxOnCapitalGain = (taxRate/100) * capitalGain
        self.cost = purchasePrice + taxOnCapitalGain
        print("Cost ")
        print("$", self.cost)
        print("")
        

    def calculateNetProfit(self):
        self.netProfit = self.proceeds - self.cost
        print("Net Profit ")
        print("$", self.netProfit)
        print("")
        
    def calculateReturnOnInvestment(self):
        self.returnOnInvestment = (self.netProfit/self.cost) * 100
        print("Return on Investment ")
        print(self.returnOnInvestment,"%")
        print("")
        
    def calculateBreakEvenPrice(self, allotment, initialSharePrice, buyCommission, sellCommission):
        breakEvenPrice = ((buyCommission + sellCommission)/allotment) + initialSharePrice
        print("To break even, you should have a final share price of ")
        print("$", breakEvenPrice)
        print("")
	
obj = StockProfitCalculator()
obj.calculate()