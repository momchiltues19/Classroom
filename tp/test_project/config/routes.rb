Rails.application.routes.draw do
  resources :member_teams
  resources :members
  resources :teams
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
