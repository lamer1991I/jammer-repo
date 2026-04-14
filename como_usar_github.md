# 🚀 Cómo crear el repositorio en GitHub

## Pasos (desde tu computador con Git)

### 1. Crear cuenta/repositorio en GitHub
- Ve a https://github.com
- Inicia sesión (o crea cuenta)
- Clic en **"New repository"** (botón verde)
- Nombre sugerido: `jammer-bluetooth-b191`
- Descripción: `Proyecto académico - Inhibidor de señal BT - Electromagnetismo B191 UTS 2026`
- Seleccionar: **Public**
- NO marcar "Add README" (ya lo tienes)
- Clic en **"Create repository"**

### 2. Subir los archivos (en tu terminal Kali/Ubuntu)
```bash
# Navegar a la carpeta del proyecto
cd /ruta/a/jammer-repo/

# Inicializar git
git init

# Agregar todos los archivos
git add .

# Primer commit
git commit -m "Primer commit - Avance No.1 y estructura base del proyecto"

# Conectar con GitHub (reemplazar TU_USUARIO con tu usuario de GitHub)
git remote add origin https://github.com/TU_USUARIO/jammer-bluetooth-b191.git

# Subir
git branch -M main
git push -u origin main
```

### 3. Compartir el link en el grupo
Una vez subido, el link será:
`https://github.com/TU_USUARIO/jammer-bluetooth-b191`

---

## Para actualizaciones futuras (cada semana)
```bash
git add .
git commit -m "Avance No.2 - Marco teórico actualizado"
git push
```

