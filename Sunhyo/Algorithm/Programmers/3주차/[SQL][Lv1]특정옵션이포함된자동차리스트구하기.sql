select CAR_ID, CAR_TYPE, DAILY_FEE, OPTIONS
from car_rental_company_car
where options like '%네비게이션%'
ORDER BY CAR_ID DESC