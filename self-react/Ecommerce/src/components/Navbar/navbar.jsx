import React from 'react'
import Logo from "../../assets/Logo.png"
import { FaSearch } from "react-icons/fa";
import { MdOutlineShoppingCart } from "react-icons/md";
import DarkModeToggle from './DarkMode';

const Menu = [
  {
    id : 1,
    name : "Home",
    link : "/#"
  },
  {
    id : 2,
    name : "Top Rated",
    link : "/#"
  },
  {
    id : 3,
    name : "Kids Wear",
    link : "/#"
  },
  {
    id : 4,
    name : "Mens Wear",
    link : "/#"
  },
  {
    id : 5,
    name : "Electronics",
    link : "/#"
  }
]

function navbar() {
  return (
    <div className='shadow-md bg-white text-black dark:bg-gray-900 dark:text-white z-40'>
      <div className='bg-[#FFF085] dark:bg-[#c08332] px-7 py-3'>  
        <div className="container mx-auto flex justify-between items-center">
          <div>
            <a href="#" className='flex gap-3 font-bold text-3xl items-center'>
              <img src={Logo} alt="Logo" className='w-8.5'/>
              Shopshop
            </a>
          </div>
          <div className='flex justify-between items-center gap-4'>
            <div className='relative group items-center gap3'>
              <input 
                type="Text"
                placeholder="Search"
                className='w-[200px] group-hover:w-[350px] transition-all px-3 py-1.5 pl-4 rounded-full bordor bordor-gray-300 bg-white dark:bg-gray-700 text-black dark:text-white duration-200'
              />
              <FaSearch className='text-gray-500 dark:text-gray-200 group-hover:text-[#ff9d1a] dark:group-hover:text-gray-200 absolute top-[50%] -translate-y-1/2 right-4'/>
            </div>
            <div>
                <button
                  onClick={() => alert("This feature is currently not avaliable!")}
                  className='group bg-gradient-to-r from-[#ffbc64] to-[#FCB454] dark:bg-gradient-to-r dark:from-[#dc9e4d] dark:to-[#ffb859] transition-all duration-500 text-white px-4 py-1.5 rounded-full flex items-center grap-3 cursor-pointer'
                >
                  <MdOutlineShoppingCart className='text-2xl text-white drop-shadow-sm'/>
                  <span className='ml-1 group-hover:block hidden transition-all duration-200'>Order</span>
                </button>
              </div>
              <div>
                  <DarkModeToggle/>
                </div>
            </div>
          </div>
      </div>
    </div>
  )
}

export default navbar