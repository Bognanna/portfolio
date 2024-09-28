package put.io.testing.junit;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    private Calculator calculator;

    @BeforeEach
    void beforeEach(){
        calculator = new Calculator();
    }

    //Question 3.1: It didn't stopped.

    @Test
    void testAddShouldAddTwoIntegers(){
        //given
        int a = 10;
        int b = 20;
        //when
        int result = calculator.add(a, b);
        //then
        Assertions.assertEquals(30, result);
    }

    @Test
    void testAddShouldAddTwoIntegersOnNegativeFirstArgument(){
        //given
        int a = -10;
        int b = 20;
        //when
        int result = calculator.add(a, b);
        //then
        Assertions.assertEquals(10, result);
    }

    @Test
    void testAddShouldAddTwoIntegersOnNegativeSecondArgument(){
        //given
        int a = 10;
        int b = -20;
        //when
        int result = calculator.add(a, b);
        //then
        Assertions.assertEquals(-10, result);
    }

    @Test
    void testMultiplyShouldMultiplyTwoIntegers(){
        //given
        int a = 10;
        int b = 20;
        //when
        int result = calculator.multiply(a, b);
        //then
        Assertions.assertEquals(200, result);
    }

    @Test
    void testMultiplyShouldMultiplyTwoIntegersOnNegativeFirstArgument(){
        //given
        int a = -10;
        int b = 20;
        //when
        int result = calculator.multiply(a, b);
        //then
        Assertions.assertEquals(-200, result);
    }

    @Test
    void testMultiplyShouldMultiplyTwoIntegersOnNegativeSecondArgument(){
        //given
        int a = 10;
        int b = -20;
        //when
        int result = calculator.multiply(a, b);
        //then
        Assertions.assertEquals(-200, result);
    }

    @Test
    void testAddPositiveNumbersShouldThrowNegativeNumbersException(){
        //given
        int a = -10;
        int b = 20;
        //when
        IllegalArgumentException thrown = Assertions.assertThrows(IllegalArgumentException.class, () -> {
            calculator.addPositiveNumbers(a, b);
        }, "The arguments must be positive");
        //then
        Assertions.assertEquals("The arguments must be positive", thrown.getMessage());
    }
}