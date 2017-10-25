#pragma once
// Установить строку предназначения для текущего стека формул
#define setSPurp(str) res.purpose = str

// Установить строку предназначения для послденей формулы
#define setFPurp(str) res.get_last().purpose = str

// Наименования стэков формул для семи стандартных этапов сборки
#define HS_STACK_1 "Сборка правильного креста"
#define HS_STACK_2 "Сборка первого слоя"
#define HS_STACK_3 "Сборка второго слоя"
#define HS_STACK_4 "Сборка желтого креста"
#define HS_STACK_5 "Сборка желтой стороны"
#define HS_STACK_6 "Сборка углов последнего слоя"
#define HS_STACK_7 "Сброка углов последнего слоя"

// Предназначения формул
#define HS_FORM_POS_WHITE_EDG "Установка на место белого реберного элемента"
#define HS_FORM_POS_WHITE_CRN "Установка на место белого углового элемента"


#define HS_FORM_MID_EDG_LFT "Установка ребра среднего слоя налево"
#define HS_FORM_MID_EDG_RGHT "Установка ребра среднего слоя налево"
#define HS_FORM_MID_EXTRACT "\"Вытаскиваем\" средний реберный элемент с чужого места"


#define HS_FORM_YLW_CROSS_STICK "Формула \"Палка\""
#define HS_FORM_YLW_CROSS_DAW "Формула \"Галка\""
#define HS_FORM_YLW_CROSS_DOT "Формула \"Точка\""

#define HS_FORM_YLW_LYR_D_EYES "Формула \"Двойные глаза\""
#define HS_FORM_YLW_LYR_HELI "Формула \"Вертолет\""
#define HS_FORM_YLW_LYR_EYES "Формула \"Глаза\""
#define HS_FORM_YLW_LYR_EARS "Формула \"Уши\""
#define HS_FORM_YLW_LYR_EIGHT "Формула \"Восемь\""
#define HS_FORM_YLW_LYR_L_FISH "Формула \"Левая рыбка\""
#define HS_FORM_YLW_LYR_R_FISH "Формула \"Правая рыбка\""

#define HS_FORM_BOT_CRN_CYCLIC_SHIFT_ACKW "Формула циклическго сдвига угловых элементов против часовой стрелки"
#define HS_FORM_BOT_CRN_CYCLIC_SHIFT_CKW "Формула циклическго сдвига угловых элементов по часовой стрелке"
#define HS_FORM_BOT_CRN_BOT_CORNS_DIAGONAL_SWITCH "Формула обмена угловых элементов по диагонали"
#define HS_FORM_BOT_CRN_DONE "Подстройка"

#define HS_FORM_BOT_EDG_TRIANGLE_CKW "Формула \"Треугольник\" по часовой"
#define HS_FORM_BOT_EDG_TRIANGLE_ACKW "Формула \"Треугольник\" против часовой"
#define HS_FORM_BOT_EDG_SLAIGH "Формула \"Саночки\""
#define HS_FORM_BOT_EDG_CROSS "Формула \"Крест-накрест\""