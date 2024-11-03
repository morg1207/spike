# Funcionalides de commit

feat: Cuando agregas una nueva funcionalidad.
fix: Para corrección de errores.
refactor: Para cambios en el código que no afectan la funcionalidad.
docs: Para cambios en la documentación.
style: Para cambios de formato, como espacios o puntos y comas.
test: Para agregar o modificar pruebas.
chore: Cambios de configuración o mantenimiento que no afectan el código de producción.

```diff
feat: implementar recuperación de contraseña

Se añadió una funcionalidad de recuperación de contraseña que permite a los usuarios
recibir un enlace de restablecimiento en su correo electrónico. 

- Generación de token seguro de un solo uso
- Envío de correo mediante el servicio de notificaciones
- Expiración del token configurada a 1 hora

Closes #45
```