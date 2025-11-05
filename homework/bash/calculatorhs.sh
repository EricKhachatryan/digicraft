#!/usr/bin/env bash

HISTFILE="$HOME/.calc_history"
touch "$HISTFILE"

echo "Простой Bash калькулятор (введите 'help' для справки)"

show_help() {
  echo "Команды:"
  echo "  help     - показать помощь"
  echo "  history  - показать историю"
  echo "  clear    - очистить историю"
  echo "  quit     - выйти"
  echo
  echo "Примеры выражений:"
  echo "  2+2"
  echo "  (3+5)*2"
  echo "  10/3"
  echo
}

while true; do
  read -rp "calc> " expr

  [[ -z "$expr" ]] && continue

  case "$expr" in
    quit|exit|q)
      echo "Выход."
      break
      ;;
    help)
      show_help
      continue
      ;;
    history)
      if [[ -s "$HISTFILE" ]]; then
        nl -ba "$HISTFILE"
      else
        echo "(история пуста)"
      fi
      continue
      ;;
    clear)
      > "$HISTFILE"
      echo "История очищена."
      continue
      ;;
  esac

  # Проверяем что есть bc
  if ! command -v bc >/dev/null 2>&1; then
    echo "Ошибка: не найден 'bc'. Установите: sudo apt install bc"
    continue
  fi

  # Вычисление выражения
  result=$(echo "scale=10; $expr" | bc -l 2>/dev/null)
  if [[ -z "$result" ]]; then
    echo "Ошибка вычисления!"
    continue
  fi

  # Убираем лишние нули
  result=$(echo "$result" | sed -E 's/\.0+$//; s/(\.[0-9]*[1-9])0+$/\1/')

  # Печатаем результат и сохраняем в историю
  echo "= $result"
  echo "$(date '+%Y-%m-%d %H:%M:%S') | $expr = $result" >> "$HISTFILE"
done

