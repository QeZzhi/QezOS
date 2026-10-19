#ifndef OS_H
#define OS_H

#ifdef __cplusplus
extern "C" {
#endif

// Объявление функций режимов загрузки
void StandartBoot(void);
void AdvancedOptionsBoot(void);
void SecureBoot(void);

#ifdef __cplusplus
}
#endif

#endif // OS_H