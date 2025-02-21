cpf1 = input('3 primeiros dígitos do cpf: ')
cpf2 = input('Próximos 3 dígitos do cpf: ')
cpf3 = input('Próximos 3 dígitos do cpf: ')
cpf4 = input('Últimos 2 dígitos do cpf: ')

print(cpf1,cpf2,cpf3, sep='.',end='-')
print(cpf4)
print(f'{cpf1}.{cpf2}.{cpf3}-{cpf4}')
