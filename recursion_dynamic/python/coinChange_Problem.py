


def rec_coin_dynam(target,coins,known_results):
    
    #Default output to target
    min_coins = target
    
    # Base Case
    if target in coins:
        known_results[target]=1
        return 1
    # Return a known result if it happens to be greater than 1
    elif known_results[target]>0:
        return known_results[target]
    
    else:
        #For every coin value that is <= target
        for i in [c for c in coins if c<=target]:
            num_coins = 1+rec_coin_dynam(target-i,coins,known_results)
            if num_coins<min_coins:
                min_coins = num_coins
                
                #Reset that known result
                
                known_results[target]=min_coins
    return min_coins




# target = 74
# coins = [1,5,10,25]
# known_results = [0]*(target+1)
# rec_coin_dynam(target,coins,known_results)


import unittest

class TestCoins(unittest.TestCase):
    def test(self,func):
        target1 = 74
        target2=45
        target3=23
        coins = [1,5,10,25]
        known_results1 = [0]*(target1+1)
        known_results2 = [0]*(target2+1)
        known_results3 = [0]*(target3+1)
        coins=[1,5,10,25]
        self.assertEqual(func(target1,coins,known_results1),8)
        self.assertEqual(func(target2,coins,known_results2),3)
        self.assertEqual(func(target3,coins,known_results3),5)
        
        print('ALL TEST CASES PASSED')

# #RUN TESTS
t = TestCoins()
t.test(rec_coin_dynam)

