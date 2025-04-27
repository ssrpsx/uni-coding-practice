/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./project12/*.html"],
  theme: {
    extend: {
      colors: {
        'primary':'000000',
        'bg-search':'#ebfffc',
        'color-search':'#555',
        'bg-button':'#ebfffc',
        'bg-project3':'#fff',
        'bg-project3.1':'#001e4d',
        'bg-pj7':'#262a2f'
      },
      maxHeight: {
        'base': '640px',
        'sm-base': '660px'
      }
    },
  },
  plugins: [],
}

