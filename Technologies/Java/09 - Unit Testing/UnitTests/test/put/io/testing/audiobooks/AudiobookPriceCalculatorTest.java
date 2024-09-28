package put.io.testing.audiobooks;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AudiobookPriceCalculatorTest {
    private AudiobookPriceCalculator calculator;
    private Customer customer;
    private Audiobook audiobook;

    @BeforeEach
    void beforeEach(){
        calculator = new AudiobookPriceCalculator();
    }

    @Test
    void testCalculateCustomerIsSubscriber(){
        //given
        customer = new Customer("A1", Customer.LoyaltyLevel.STANDARD, true);
        audiobook = new Audiobook("A2", 30);
        //when
        double result = calculator.calculate(customer, audiobook);
        //then
        Assertions.assertEquals(0, result);
    }

    @Test
    void testCalculateSilverCustomer(){
        //given
        customer = new Customer("A1", Customer.LoyaltyLevel.SILVER, false);
        audiobook = new Audiobook("A2", 100);
        //when
        double result = calculator.calculate(customer, audiobook);
        //then
        Assertions.assertEquals(90, result);
    }

    @Test
    void testCalculateGoldCustomer(){
        //given
        customer = new Customer("A1", Customer.LoyaltyLevel.GOLD, false);
        audiobook = new Audiobook("A2", 100);
        //when
        double result = calculator.calculate(customer, audiobook);
        //then
        Assertions.assertEquals(80, result);
    }
}