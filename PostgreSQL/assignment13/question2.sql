-- Q2. Write a PL/SQL block to accept two numbers using substitution variables and then find their sum, difference, product and quotient

\prompt 'Enter first number: ' num1
\prompt 'Enter second number: ' num2

SELECT SET_CONFIG('my.num1', :'num1', FALSE);
SELECT SET_CONFIG('my.num2', :'num2', FALSE);

DO $$
    DECLARE
        a FLOAT := CURRENT_SETTING('my.num1')::FLOAT;
        b FLOAT := CURRENT_SETTING('my.num2')::FLOAT;

    BEGIN
        RAISE NOTICE 'Sum = %', a + b;
        RAISE NOTICE 'Difference = %', a - b;
        RAISE NOTICE 'Product = %', a * b;
        RAISE NOTICE 'Quotient = %', a / b;
    END;
$$;
